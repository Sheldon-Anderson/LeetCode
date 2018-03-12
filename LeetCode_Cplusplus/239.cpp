#include<bits/stdc++.h>
using namespace std;

/*
// Accepted
// deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()){
			return vector<int>();
		}
		int n = nums.size();
		deque<int> dq;
		vector<int> ans;
		for(int i = 0; i <= n - 1; i++){
			while(!dq.empty() && i - dq.front() >= k){
				dq.pop_front();
			}
			while(!dq.empty() && nums[dq.back()] <= nums[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			if(i >= k - 1){
				ans.push_back(nums[dq.front()]);
			}
		}
		return ans;
    }
};
*/

// heap sort + DFS
class Solution {
private: 
	bool flag;
	
	// build max heap
	void max_heapify(vector<int> &arr, int start, int end){
		int dad = start;
		int son = 2 * dad + 1;
		while(son <= end){
			if(son + 1 <= end && arr[son] < arr[son + 1]){
				son++;
			}
			if(arr[dad] > arr[son]){
				return;
			}
			else{
				swap(arr[dad], arr[son]);
				dad = son;
				son = 2 * dad + 1;
			}
		}
	}
	
	// DFS
	void DFS(vector<int> &arr, int i, int len, int oldVal, int newVal){
		if(i >= len || flag){
			return;
		}
		if(arr[i] == oldVal){
			arr[i] = newVal;
			// check leaf node
			int pos = i;
			if(pos > (len / 2 - 1)){
				pos = (pos - 1) / 2;
			}
			for(int j = pos; j >= 0; j--){
				max_heapify(arr, j, len - 1);
			}
			flag = true;
			return;
		}
		DFS(arr, 2 * i + 1, len, oldVal, newVal);
		DFS(arr, 2 * i + 2, len, oldVal, newVal);
	}

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if(nums.empty()){
			return vector<int>();
		}
		int n = nums.size();
		vector<int> arr(nums.begin(), nums.begin() + k);
		vector<int> ans;
		// heap sort for first k values
		for(int i = k / 2 - 1; i >= 0; i--){
			max_heapify(arr, i, k - 1);
		}
		ans.push_back(arr[0]);
		// n - k steps
		for(int i = k; i <= n - 1; i++){
			flag = false;
			DFS(arr, 0, k, nums[i - k], nums[i]);
			ans.push_back(arr[0]);
		}
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	vector<int> ans = sol.maxSlidingWindow(nums, k);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
