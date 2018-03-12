#include<bits/stdc++.h>
using namespace std;

#define MAX_CHILD 26

class Solution {
private: 
	struct TrieNode{
		int count;
		TrieNode *child[MAX_CHILD];
		TrieNode(){
			count = 0;
			for(int i = 0; i <= MAX_CHILD - 1; i++){
				child[i] = NULL;
			}
		}
	};
	
	TrieNode *root = NULL;
	vector<string> ans;

	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	
	void insert(string word){
		int n = word.length();
		if(!root || !n){
			return;
		}
		TrieNode *t = root;
		for(int i = 0; i <= n - 1; i++){
			int index = word[i] - 'a';
			if(!t->child[index]){
				TrieNode *temp = new TrieNode();
				t->child[index] = temp;
			}
			t = t->child[index];
		}
		t->count++;
	}
	
	int search(string word){
		int n = word.length();
		if(!root || !n){
			return 0;
		}
		TrieNode *t = root;
		int i = 0;
		for(; i <= n - 1; i++){
			int index = word[i] - 'a';
			if(t->child[index]){
				t = t->child[index];
			}
			else{
				break;
			}
		}
		// 2: find word, 1: find prefix, 0: find nothing
		if(i == n && t->count > 0){
			return 2;
		}
		else if(i == n && !t->count){
			return 1;
		}
		return 0;
	}
	
	void DFS(vector<vector<char>>& board, int m, int n, int x, int y, string res){
		int flag = search(res);
		if(flag == 0){
			return;
		}
		if(flag == 2){
			if(find(ans.begin(), ans.end(), res) == ans.end()){
				ans.push_back(res);
			}
		}
		for(int i = 0; i <= 3; i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && board[xx][yy] != '.'){
				char pre = board[xx][yy];
				board[xx][yy] = '.';
				DFS(board, m, n, xx, yy, res + pre);
				board[xx][yy] = pre;
			}
		}
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Exceptional Case: 
		if(board.empty()){
			return ans;
		}
		int m = board.size(), n = board[0].size();
		if(m == 0 || n == 0){
			return ans;
		}
		int len = words.size();
		if(len == 0){
			return ans;
		}
		// create root TrieNode
		root = new TrieNode();
		// insert
		for(string word: words){
			insert(word);
		}
		// DFS search
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				char pre = board[i][j];
				board[i][j] = '.';
				string res = "";
				res += pre;
				DFS(board, m, n, i, j, res);
				board[i][j] = pre;
			}
		}
		return ans;
	}
};

int main(){
	Solution sol;
	vector<vector<char>> board = {
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};
	vector<string> words = {"oath", "pea", "eat", "rain"};
	vector<string> ans = sol.findWords(board, words);
	// console output
	for(string str: ans){
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
