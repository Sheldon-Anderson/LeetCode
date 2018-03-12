#include<bits/stdc++.h>
using namespace std;

// DFS + BFS
class Solution {
private: 
	vector<vector<string>> ans;
	map<string, set<pair<string, int>>> parent;

	// get all the valid paths
	void DFS(set<pair<string, int>> s, vector<string> v){
		for(auto &p: s){
			v.push_back(p.first);
			if(!parent.count(p.first)){
				reverse(v.begin(), v.end());
				ans.push_back(v);
				return;
			}
			DFS(parent[p.first], v);
			v.pop_back();
		}
	}
	
	// find all the shortest paths
	void BFS(string beginWord, string endWord, set<string> &wordSet){
		// current word, steps
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while(!q.empty()){
			pair<string, int> p = q.front();
			q.pop();
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
						parent[temp].insert(p);
					}
					// A->B->C->E, A->D->C->E
					else if(!wordSet.count(temp) && parent.count(temp) && parent[temp].begin()->second == p.second){
						parent[temp].insert(p);
					}
				}
			}
		}
		DFS(parent[endWord], vector<string>{endWord});
	}

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		// clear
		ans.clear();
		parent.clear();
		// vector -> set
		set<string> wordSet(wordList.begin(), wordList.end());
		int n = wordSet.size();
		// Case 1: 
		if(beginWord == endWord){
			ans.push_back({beginWord});
			return ans;
		}
		// Case 2: 
		if(n == 0){
			return ans;
		}
		wordSet.erase(beginWord);
		// wordSet.insert(endWord); will cause an error!
		BFS(beginWord, endWord, wordSet);
        return ans;
    }
};

int main(){
	Solution sol;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);
	// console output
	for(auto &p: ans){
		for(string val: p){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
