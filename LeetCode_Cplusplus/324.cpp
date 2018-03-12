#include <bits/stdc++.h>
using namespace std;

/*
// sort
// T(n) = O(nlogn)
// S(n) = O(n)
// Accepted
class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return;
		}
		vector<int> vec(nums);
		// sort
		sort(vec.begin(), vec.end(), cmp);
		// move
		int left = (n - 1) / 2, right = n - 1;
		int pos = 0;
		while(pos <= n - 1){
			nums[pos] = vec[left--];
			pos += 2;
		}
		pos = 1;
		while(pos <= n - 1){
			nums[pos] = vec[right--];
			pos += 2;
		};
    }
};
*/

/*
// find k smallest
// T(n) = O(n)
// S(n) = O(n)
// Accepted
class Solution{
private: 
	// partition
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
		swap(nums[j], nums[left]);
		return j;
	}

	// find k smallest
	int findMedian(vector<int>& nums, int k){
		int left = 0, right = nums.size() - 1;
		while(left <= right){
			int pos = partition(nums, left, right);
			if((pos + 1) == k){
				break;
			}
			else if((pos + 1) < k){
				left = pos + 1;
			}
			else if((pos + 1) > k){
				right = pos - 1;
			}
		}
		return nums[k - 1];
	}

public:
    void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return;
		}
		// get median
		int median = findMedian(nums, (n + 1) / 2);
		// create and assign
		int *vec = new int[n];
		int start = 0, end = n - 1;
		for(int i = 0; i <= n - 1; i++){
			if(nums[i] > median){
				vec[start++] = nums[i];
			}
			else if(nums[i] < median){
				vec[end--] = nums[i];
			}
		}
		for(int i = start; i <= end; i++){
			vec[i] = median;
		}
		int pos = 1;
		for(int i = 0; i <= n / 2 - 1; i++){
			nums[pos] = vec[i];
			pos += 2;
		}
		pos = 0;
		for(int i = n / 2; i <= n - 1; i++){
			nums[pos] = vec[i];
			pos += 2;
		}
	}
};
*/

// find k smallest
// T(n) = O(n)
// S(n) = O(1)
class Solution{
private: 
	// partition
	int partition(vector<int> &nums, int left, int right){
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
		swap(nums[j], nums[left]);
		return j;
	}

	// find k smallest
	int findKSmallest(vector<int> &nums, int k){
		int left = 0, right = nums.size() - 1;
		while(left < right){
			int pos = partition(nums, left, right);
			if((pos + 1) == k){
				break;
			}
			else if((pos + 1) < k){
				left = pos + 1;
			}
			else if((pos + 1) > k){
				right = pos - 1;
			}
		}
		return nums[k - 1];
	}
	
	// update the index
	int updateIndex(int index, int n){
		return (1 + 2 * index) % (n | 1);
	}

public:
    void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return;
		}
		// get median
		int median = findKSmallest(nums, (n + 1) / 2);
		int left = 0, right = n - 1;
		int i = 0;
		while(i <= right){
			if(nums[updateIndex(i, n)] > median){
				swap(nums[updateIndex(left++, n)], nums[updateIndex(i++, n)]);
			}
			else if(nums[updateIndex(i, n)] < median){
				swap(nums[updateIndex(right--, n)], nums[updateIndex(i, n)]);
			}
			else{
				i++;
			}
		}
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5};	// {1, 3, 2, 2, 3, 1};
	sol.wiggleSort(nums);
	return 0;
}
