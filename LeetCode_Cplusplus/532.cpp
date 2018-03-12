#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
		if(!n || k < 0){
			return 0;
		}
		map<int, int> m;
		for(int key: nums){
			m[key]++;
		}
		int count = 0;
		if(!k){
			for(auto itm: m){
				if(itm.second >= 2){
					count += 1;
				}
			}
		}
		else{
			for(auto itm: m){
				if(m.count(itm.first + k)){
					count += 1;
				}
			}
		}
		return count;
    }
};

int main(){
	
	return 0;
}