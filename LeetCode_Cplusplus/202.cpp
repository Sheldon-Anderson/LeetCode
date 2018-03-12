#include<bits/stdc++.h>
using namespace std;

// set
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1){
			return true;
		}
		int pre = n, cur = 0;
		// for case: n = 2
		set<int> s;
		s.insert(pre);
		while(true){
			while(pre){
				cur += (pre % 10) * (pre % 10);
				pre /= 10;
			}
			if(cur == 1){
				return true;
			}
			if(s.count(cur)){
				break;
			}
			s.insert(cur);
			pre = cur;
			cur = 0;
		}
		return false;
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.isHappy(n) << endl;
	}
	return 0;
}
