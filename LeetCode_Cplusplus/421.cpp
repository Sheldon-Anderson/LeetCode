#include<bits/stdc++.h>

using namespace std;

/*
// set + bit manipulation
// a ^ b = c => a ^ c = b, b ^ c = a
// Accepted
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return 0;
		}
		int ans = 0, mask = 0;
		// from high bits to low bits
		for(int i = 31; i >= 0; i--){
			mask |= (1 << i);
			set<int> s;
			for(int num: nums){
				s.insert(num & mask);
			}
			int temp = ans | (1 << i);
			for(int prefix: s){
				if(s.count(temp ^ prefix)){
					ans = temp;
					break;
				}
			}
		}
		// get answer
		return ans;
    }
};
*/

// trie tree
class TrieNode{
public: 
	TrieNode *child[2];
	TrieNode(){
		child[0] = child[1] = NULL;
	}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return 0;
		}
		// insert
		TrieNode *root = new TrieNode();
		for(int num: nums){
			TrieNode *T = root;
			// from high bits to low bits
			for(int i = 31; i >= 0; i--){
				int bit = (num >> i) & 1;
				if(!T->child[bit]){
					T->child[bit] = new TrieNode();
				}
				T = T->child[bit];
			}
		}
		// get max XOR answer
		int ans = INT_MIN;
		for(int num: nums){
			TrieNode *T = root;
			int res = 0;
			// from high bits to low bits
			for(int i = 31; i >= 0; i--){
				int bit = (num >> i) & 1;
				if(T->child[bit ^ 1]){
					res += (1 << i);
					T = T->child[bit ^ 1];
				}
				else{
					T = T->child[bit];
				}0
			
			}
			// update answer
			ans = max(ans, res);
		}
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {3, 10, 5, 25, 2, 8};
	cout << "ans: " << sol.findMaximumXOR(nums) << endl;
	return 0;
}
