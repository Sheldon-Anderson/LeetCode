#include<bits/stdc++.h>
using namespace std;

// count / map
class Solution {
public:
    int hIndex(vector<int>& citations) {
		int n = citations.size();
		if(n == 0){
			return 0;
		}
		// count
		vector<int> cnt(n + 1, 0);
		for(int i = 0; i <= n - 1; i++){
			if(citations[i] < n){
				cnt[citations[i]]++;
			}
			else{
				cnt[n]++;
			}
		}
		// get answer
		int count = 0;
		for(int i = n; i >= 0; i--){
			count += cnt[i];
			if(count >= i){
				return i;
			}
		}
		return 0;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> citations = {3, 0, 6, 1, 5};
	cout << "ans: " <<  sol.hIndex(citations) << endl;
	return 0;
}
