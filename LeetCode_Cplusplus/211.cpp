#include<bits/stdc++.h>
using namespace std;

// 'a' -> 'z', '.'
#define MAX_CHILD 27

class TrieNode{
public: 
	int count;
	TrieNode *child[MAX_CHILD];
	TrieNode(){
		count = 0;
		for(int i = 0; i <= MAX_CHILD - 1; i++){
			child[i] = NULL;
		}
	}
};

class WordDictionary {
private: 
	TrieNode *root = NULL;
	bool ans;
	
	void DFS(string word, TrieNode *t, int n, int k){
		if(ans){
			return;
		}
		if(k == n && t->count > 0){
			ans = true;
			return;
		}
		if(!t || k >= n){
			return;
		}
		if(word[k] == '.'){
			for(int i = 0; i <= MAX_CHILD - 1; i++){
				if(t->child[i]){
					DFS(word, t->child[i], n, k + 1);
				}
			}
		}
		else if(word[k] != '.'){
			if(t->child[word[k] - 'a']){
				DFS(word, t->child[word[k] - 'a'], n, k + 1);
			}
		}
	}

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.length();
		// Exceptional Case: 
		if(!root || !n){
			return;
		}
		TrieNode *t = root;
		for(int i = 0; i <= n - 1; i++){
			int index = (word[i] == '.')? 26: (word[i] - 'a');
			if(!t->child[index]){
				TrieNode *temp = new TrieNode();
				t->child[index] = temp;
			}
			t = t->child[index];
		}
		t->count++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int n = word.length();
		ans = false;
		TrieNode *t = root;
		DFS(word, t, n, 0);
		return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main(){
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	string word;
	while(cin >> word){
		bool search = wd.search(word);
		cout << "search: " << search << endl;
		if(!search){
			wd.addWord(word);
			cout << "add word successfully!" << endl;
		}
	}
	return 0;
}
