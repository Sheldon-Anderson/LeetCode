#include<bits/stdc++.h>
using namespace std;

/*
// Find the kth largest element in an unsorted array
// sort
class Solution {
private: 
	static int cmp(const int a, const int b){
		return a > b;
	}

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		sort(nums.begin(), nums.end(), cmp);
		return nums[k - 1];
    }
};
*/

/*
// priority_queue
class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		// descending
		priority_queue<int, vector<int>, less<int>> pq;
		for(int val: nums){
			pq.push(val);
		}
		for(int i = 1; i <= k - 1; i++){
			pq.pop();
		}
		return pq.top();
	}
};
*/

/*
// heap sort
class Solution{
private: 
	void max_heapify(vector<int>& nums, int start, int end){
		int dad = start;
		int son = dad * 2 + 1;
		while(son <= end){
			if(son + 1 <= end && nums[son] < nums[son + 1]){
				son++;
			}
			if(nums[dad] > nums[son]){
				return;
			}
			else{
				swap(nums[dad], nums[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}

	int heap_sort(vector<int>& nums, int n, int k){
		// sort
		for(int i = n / 2 - 1; i >= 0; i--){
			max_heapify(nums, i, n - 1);
		}
		// delete
		for(int i = n - 1; i >= n - k; i--){
			swap(nums[0], nums[i]);
			max_heapify(nums, 0, i - 1);
		}
		return nums[n - k];
	}

public:
    int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		// Exceptional Case: 
		if(n == 0){
			return 0;
		}
		return heap_sort(nums, n, k);
	}
};
*/

// quicksort partition function
class Solution{
private: 
	// quicksort partition function
	int partition(vector<int>& nums, int left, int right){
		int i = left, j = right + 1;
		int pivot = nums[left];
		while(true){
			while(nums[++i] < pivot && i < right);
			while(nums[--j] > pivot && j > left);
			if(i >= j){
				break;
			}
			swap(nums[i], nums[j]);
		}
		swap(nums[left], nums[j]);
		return j;
	}

	// binary search
	int findK(vector<int>& nums, int left, int right, int k){
		while(left < right){
			int pos = partition(nums, left, right);
			if(pos + 1 == k){
				break;
			}
			else if(pos + 1 > k){
				right = pos - 1;
			}
			else if(pos + 1 < k){
				left = pos + 1;
			}
		}
		// get answer
		return nums[k - 1];
	}
/*
	// recursion
	int findK2(vector<int>& nums, int left, int right, int k){
		if(left >= right){
			return nums[right];
		}
		int pos = partition(nums, left, right);
		int cnt = pos - left + 1;
		int ans = -1;
		if(cnt == k){
			ans = nums[pos];
		}
		else if(cnt < k){
			ans = findK2(nums, pos + 1, right, k - cnt);
		}
		else if(cnt > k){
			ans = findK2(nums, left, pos - 1, k);
		}
		return ans;
	}
*/
public:
    int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		return findK(nums, 0, n - 1, n + 1 - k);
		// return findK2(nums, 0, n - 1, n + 1 - k);
	}
};

int main(){
	Solution sol;
	int k;
	while(cin >> k){
		vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
		cout << "ans: " << sol.findKthLargest(nums, k) << endl;
	}
	return 0;
}
