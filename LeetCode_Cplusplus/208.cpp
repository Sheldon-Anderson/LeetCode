#include<bits/stdc++.h>
using namespace std;

#define MAX_CHILD 26

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

class Trie {
private: 
	TrieNode *root = NULL;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
		// Exceptional Case: 
		if(!root || !n){
			return;
		}
		TrieNode *t = root;
		for(int i = 0; i <= n - 1; i++){
			if(!t->child[word[i] - 'a']){
				TrieNode * temp = new TrieNode();
				t->child[word[i] - 'a'] = temp;
			}
			t = t->child[word[i] - 'a'];
		}
		t->count++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
		// Exceptional Case: 
		if(!root || !n){
			return false;
		}
		TrieNode *t = root;
		int i;
		for(i = 0; i <= n - 1; i++){
			if(t->child[word[i] - 'a']){
				t = t->child[word[i] - 'a'];
			}
			else{
				break;
			}
		}
		return i == n && t->count > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
		// Exceptional Case: 
		if(!root || !n){
			return false;
		}
		TrieNode *t = root;
		int i;
		for(i = 0; i <= n - 1; i++){
			if(t->child[prefix[i] - 'a']){
				t = t->child[prefix[i] - 'a'];
			}
			else{
				break;
			}
		}
		return i == n;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
 
int main(){
	Trie trie;
	trie.insert("abcd");
	trie.insert("xyz");
	string word;
	while(cin >> word){
		bool search = trie.search(word);
		bool startsWith = trie.startsWith(word);
		cout << "search: " <<search << endl;
		cout << "startsWith: " << startsWith << endl;
		if(!search && !startsWith){
			trie.insert(word);
			cout << "insert successfully!" << endl;
		}
	}
	return 0;
}
