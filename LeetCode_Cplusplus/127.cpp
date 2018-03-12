#include<bits/stdc++.h>
using namespace std;

// BFS
class Solution {
private: 
	int BFS(string beginWord, string endWord, set<string>& wordSet){
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while(!q.empty()){
			pair<string, int> p = q.front();
			q.pop();
			// get answer
			if(p.first == endWord){
				return p.second;
			}
			for(int i = 0; i <= p.first.length() - 1; i++){
				string temp = p.first;
				for(int j = 0; j <= 25; j++){
					temp[i] = 'a' + j;
					if(temp == p.first){
						continue;
					}
					if(wordSet.count(temp)){
						q.push(make_pair(temp, p.second + 1));
						wordSet.erase(temp);
					}
				}
			}
		}
		return 0;
	}

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
		// Case 1: 
		if(beginWord == endWord){
			return 1;
		}
		// Case 2: 
		if(n == 0){
			return 0;
		}
		set<string> wordSet(wordList.begin(), wordList.end());
		wordSet.erase(beginWord);
		return BFS(beginWord, endWord, wordSet);
    }
};

int main(){
	Solution sol;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};	
	cout << "ans: " << sol.ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}
