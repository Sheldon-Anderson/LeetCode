#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
private: 
	TreeNode* DFS(vector<int>& nums, int start, int end){
		if(start > end){
			return NULL;
		}
		if(start == end){
			return new TreeNode(nums[start]);
		}
		int mid = (start + end) >> 1;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = DFS(nums, start , mid - 1);
		root->right = DFS(nums, mid + 1, end);
		return root;
	}

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
        if(n == 0){
			return NULL;
		}
		return DFS(nums, 0, n - 1);
    }
};

void in_output(TreeNode* T){
	if(!T){
		return;
	}
	in_output(T->left);
	cout << T->val << " ";
	in_output(T->right);
}

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
	TreeNode *ans = sol.sortedArrayToBST(nums);
	// console output
	in_output(ans);
	cout << endl;
	return 0;
}
