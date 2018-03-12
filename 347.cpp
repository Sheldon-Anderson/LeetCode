#include <bits/stdc++.h>

using namespace std;

/*
// map + priority_queue
// T(n) = O(n)
// S(n) = O(n)
// Accepted
class Solution {
private: 
	// priority_queue compare function
	// it's '>', '<' are opposed to the sort compare function
	struct cmp{
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
			if(a.first != b.first){
				return a.first < b.first;
			}
			return a.second > b.second;
		}
	};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		// count frequencies
		map<int, int> m;
        for(int num: nums){
			m[num]++;
		}
		// heap sort
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		int N = m.size();
		vector<int> ans;
		for(auto &p: m){
			pq.push(make_pair(p.second, p.first));
			if(pq.size() > N - k){
				ans.push_back(pq.top().second);
				pq.pop();
			}
		}
		// get answer
		return ans;
    }
};
*/

// map + bucket sort
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		// count
		map<int, int> m;
		for(int num: nums){
			m[num]++;
		}
		// bucket sort
		int N = nums.size();
		vector<set<int>> bucket(N + 1);
		for(auto &p: m){
			bucket[p.second].insert(p.first);
		}
		// get answer
		vector<int> ans;
		int cnt = 0;
		for(int i = N; i >= 1; i--){
			for(auto its = bucket[i].begin(); its != bucket[i].end(); its++){
				ans.push_back(*its);
				if(++cnt == k){
					break;
				}
			}
			if(cnt == k){
				break;
			}
		}
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1,1,1,1,1,2,2,2,2,3,3,3};
	int k = 2;
	vector<int> ans = sol.topKFrequent(nums, k);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
