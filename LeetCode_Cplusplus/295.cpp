#include <bits/stdc++.h>
using namespace std;

/*
// binary search
// Accepted
class MedianFinder {
private: 
	vector<int> nums;
	
	// find the first pos that nums[pos] >= target
	int binary_search(int left, int right, int target){
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(nums[mid] >= target){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		return left;
	}

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = nums.size();
		int pos = binary_search(0, n - 1, num);
		nums.insert(nums.begin() + pos, num);
    }
    
    double findMedian() {
        int n = nums.size();
		if(n == 0){
			return -1.0;
		}
		if(n & 1){
			return (double)nums[(n - 1) >> 1];
		}
		return (nums[(n - 1) >> 1] + nums[n >> 1]) / 2.0;
    }
};
*/

/*
// max heap and min heap: STL priority_queue
// Accepted
class MedianFinder {
private: 
	// max heap and min heap
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
		int max_top = max_heap.top();
		max_heap.pop();
		min_heap.push(max_top);
		int n1 = max_heap.size(), n2 = min_heap.size();
		if(n1 < n2){
			int min_top = min_heap.top();
			min_heap.pop();
			max_heap.push(min_top);
		}
    }
    
    double findMedian() {
        int n1 = max_heap.size(), n2 = min_heap.size();
		if(n1 + n2 == 0){
			return -1.0;
		}
		if((n1 + n2) & 1){
			return (double)max_heap.top();
		}
		return (max_heap.top() + min_heap.top()) / 2.0;
    }
};
*/

// max heap and min heap: DIY
class MedianFinder {
private: 
	// max heap and min heap
	vector<int> max_heap, min_heap;

	// update from up to down
	void up_down_heapify(vector<int> &nums, int start, int end, int type){
		int dad = start;
		int son = 2 * dad + 1;
		while(son <= end){
			if(son + 1 <= end && ((type == 1 && nums[son] < nums[son + 1]) || (type == 2 && nums[son] > nums[son + 1]))){
				son++;
			}
			if((type == 1 && nums[dad] > nums[son]) || (type == 2 && nums[dad] < nums[son])){
				return;
			}
			swap(nums[dad], nums[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
	
	// insert and update from down to up
	void heap_insert(vector<int> &nums, int target, int type){
		nums.push_back(target);
		int son = nums.size() - 1;
		int dad = (son - 1) / 2;
		while(dad >= 0 && son >= 1){
			// update from down to up
			if((type == 1 && nums[dad] > nums[son]) || (type == 2 && nums[dad] < nums[son])){
				return;
			}
			swap(nums[dad], nums[son]);
			son = dad;
			dad = (son - 1) / 2; 
		}
	}
	
	// delete and update from up to down
	void heap_delete(vector<int> &nums, int type){
		int n = nums.size();
		if(n == 0){
			return;
		}
		swap(nums[0], nums[n - 1]);
		nums.pop_back();
		up_down_heapify(nums, 0, n - 2, type);
	}

public:	
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        heap_insert(max_heap, num, 1);
		int max_top = max_heap[0];
		heap_delete(max_heap, 1);
		heap_insert(min_heap, max_top, 2);
		int n1 = max_heap.size(), n2 = min_heap.size();
		if(n1 < n2){
			int min_top = min_heap[0];
			heap_delete(min_heap, 2);
			heap_insert(max_heap, min_top, 1);
		}
    }
    
    double findMedian() {
        int n1 = max_heap.size(), n2 = min_heap.size();
		if(n1 + n2 == 0){
			return -1.0;
		}
		if((n1 + n2) & 1){
			return (double)max_heap[0];
		}
		return (max_heap[0] + min_heap[0]) / 2.0;
    }
};

int main(int argc, char** argv){
	MedianFinder mf;
	for(int i = 1; i <= 10; i++){
		mf.addNum(i);
		cout << "i: " << i << ", ans: " << mf.findMedian() << endl;
	}
	return 0;
}
