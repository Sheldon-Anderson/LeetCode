#include <bits/stdc++.h>
using namespace std;

/*
// next_permutation
class Solution {
private: 
	vector<int> vec_original, vec_shuffle;

public:
    Solution(vector<int> nums) {
        vec_shuffle = vec_original = nums;
    }
    
    vector<int> reset() {
        return vec_original;
    }
    
    vector<int> shuffle() {
		if(vec_shuffle.size()){
			next_permutation(vec_shuffle.begin(), vec_shuffle.end());
		}
		return vec_shuffle;
    }
};
*/

// rand()
class Solution {
private: 
	vector<int> vec_original, vec_shuffle;

public:
    Solution(vector<int> nums) {
        vec_shuffle = vec_original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec_original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = vec_shuffle.size();
		if(n){
			for(int i = 0; i <= n - 1; i++){
				int pos = rand() % (n - i) + i;
				if(pos != i){
					swap(vec_shuffle[pos], vec_shuffle[i]);
				}
			}
		}
		return vec_shuffle;
    }
};

void output(vector<int> V){
	for(int val: V){
		cout << val << " ";
	}
	cout << endl;
}

int main(int argc, char** argv){
	// Init an array with set 1, 2, and 3.
	vector<int> nums = {1,2,3};
	Solution solution(nums);
	
	vector<int> ans;
	// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
	ans = solution.shuffle();
	output(ans);
	
	// Resets the array back to its original configuration [1,2,3].
	ans = solution.reset();
	output(ans);
	
	// Returns the random shuffling of array [1,2,3].
	ans = solution.shuffle();
	output(ans);

	return 0;
}
