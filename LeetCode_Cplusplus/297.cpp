#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

#define LL long long

// level order traversal
class Codec {
private: 
	stringstream stream;

	string levelSerialize(TreeNode *root){
		if(!root){
			return "";
		}
		string ans = "", res;
		queue<TreeNode*> q;
		TreeNode *p;
		q.push(root);
		while(!q.empty()){
			p = q.front();
			q.pop();
			if(p){
				stream << p->val;
				stream >> res;
				stream.clear();
				ans += (res + " ");
				if(p->left){
					q.push(p->left);
				}
				else{
					q.push(NULL);
				}
				if(p->right){
					q.push(p->right);
				}
				else{
					q.push(NULL);
				}
			}
			else{
				ans += "N ";
			}
		}
		return ans;
	}

	TreeNode* levelDeserialize(vector<LL> &nums){
		int n = nums.size();
		if(n == 0){
			return NULL;
		}
		queue<TreeNode*> qq;
		TreeNode *root = new TreeNode((int)nums[0]), *p;
		int son = 1;
		qq.push(root);
		while(!qq.empty()){
			p = qq.front();
			qq.pop();
			if(nums[son] == LLONG_MAX){
				p->left = NULL;
			}
			else{
				p->left = new TreeNode((int)nums[son]);
				qq.push(p->left);
			}
			son++;
			if(nums[son] == LLONG_MAX){
				p->right = NULL;
			}
			else{
				p->right = new TreeNode((int)nums[son]);
				qq.push(p->right);
			}
			son++;
		}
		return root;
	}
	
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return levelSerialize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
		if(n == 0){
			return NULL;
		}
		vector<LL> nums;
		LL digit = 0;		
		istringstream iss(data);
		string str;
		while(getline(iss, str, ' ')){
			if(str == ""){
				continue;
			}
			else if(str == "N"){
				nums.push_back(LLONG_MAX);
			}
			else{
				stream << str;
				stream >> digit;
				stream.clear();
				nums.push_back(digit);
			}
		}
		return levelDeserialize(nums);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void pre(TreeNode *T){
	if(!T){
		return;
	}
	cout << T->val << " ";
	pre(T->left);
	pre(T->right);
}

void in(TreeNode *T){
	if(!T){
		return;
	}
	in(T->left);
	cout << T->val << " ";
	in(T->right);
}

int main(int argc, char** argv){
	// tree
	TreeNode *T = new TreeNode(5);
	T->left = new TreeNode(2);
	T->right = new TreeNode(3);
	// T->left->left = new TreeNode(1);
	T->right->left = new TreeNode(2);
	T->right->right = new TreeNode(4);
	T->right->left->left = new TreeNode(3);
	T->right->left->right = new TreeNode(1);
	// out 1
	pre(T);
	cout << endl;
	in(T);
	cout << endl;
	Codec cc;
	// out 2
	string ans = cc.serialize(T);
	cout << "ans: " << ans << endl;
	TreeNode *A = cc.deserialize(ans);
	pre(A);
	cout << endl;
	in(A);
	cout << endl;	
	return 0;
}
