#include<bits/stdc++.h>

using namespace std;

#define LL long long

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// level traversal
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

	TreeNode *levelDeserialize(vector<LL> vec){
		int n = vec.size();
		if(!n){
			return NULL;
		}
		TreeNode *root = new TreeNode((int)vec[0]);
		int son = 1;
		queue<TreeNode*> q;
		TreeNode *p;
		q.push(root);
		while(!q.empty()){
			p = q.front();
			q.pop();
			if(vec[son] == LLONG_MAX){
				p->left = NULL;
			}
			else{
				p->left = new TreeNode((int)vec[son]);
				q.push(p->left);
			}
			son++;
			if(vec[son] == LLONG_MAX){
				p->right = NULL;
			}
			else{
				p->right = new TreeNode((int)vec[son]);
				q.push(p->right);
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
		if(!n){
			return NULL;
		}
		// transfer from string to vector
		istringstream iss(data);
		string str;
		LL digit;
		vector<LL> vec;
		while(getline(iss, str, ' ')){
			if(str == ""){
				continue;
			}
			if(str == "N"){
				vec.push_back(LLONG_MAX);
			}
			else{
				stream << str;
				stream >> digit;
				stream.clear();
				vec.push_back(digit);
			}
		}
		// get answer
		return levelDeserialize(vec);
    }
};

void preout(TreeNode* T){
	if(!T){
		return;
	}
	cout << T->val << " ";
	preout(T->left);
	preout(T->right);
}

void inout(TreeNode* T){
	if(!T){
		return;
	}
	inout(T->left);
	cout << T->val << " ";
	inout(T->right);
}

int main(int argc, char** argv){
	Codec cc;
	TreeNode *T = new TreeNode(1);
	T->left = new TreeNode(2);
	T->right = new TreeNode(3);
	T->right->left = new TreeNode(4);
	T->right->right = new TreeNode(5);
	// out 1
	preout(T);
	cout << endl;
	inout(T);
	cout << endl;
	string str = cc.serialize(T);
	cout << "str: " << str << endl;
	TreeNode *ans = cc.deserialize(str);
	// out 2
	preout(ans);
	cout << endl;
	inout(ans);
	cout << endl;
	return 0;
}
