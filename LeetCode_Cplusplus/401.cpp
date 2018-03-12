#include<bits/stdc++.h>

using namespace std;

// DFS
class Solution {
private: 
	int LEDs[6] = {1, 2, 4, 8, 16, 32};
	vector<int> hours, minutes;
	stringstream stream;

	void DFS(bool flag, int n, int k, int pos, int res){
		if(k == n){
			if(flag){
				hours.push_back(res);
			}
			else{
				minutes.push_back(res);
			}
			return;
		}
		if(flag){
			for(int i = pos; i <= 3; i++){
				if(res + LEDs[i] <= 11){
					DFS(flag, n, k + 1, i + 1, res + LEDs[i]);
				}
			}
		}
		else{
			for(int i = pos; i <= 5; i++){
				if(res + LEDs[i] <= 59){
					DFS(flag, n, k + 1, i + 1, res + LEDs[i]);
				}
			}
		}
	}

public:
    vector<string> readBinaryWatch(int num) {
        int h_min = max(0, num - 6);
		int h_max = min(4, num);
		vector<string> ans;
		for(int i = h_min; i <= h_max; i++){
			hours.clear();
			minutes.clear();
			DFS(true, i, 0, 0, 0);
			DFS(false, num - i, 0, 0, 0);
			// add to the answer
			string strH, strM;
			for(int h: hours){
				for(int m: minutes){
					stream << h;
					stream >> strH;
					stream.clear();
					stream << m;
					stream >> strM;
					stream.clear();
					if(strM.length() == 1){
						strM = "0" + strM;
					}
					ans.push_back(strH + ":" + strM);
				}
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		vector<string> ans = sol.readBinaryWatch(num);
		// console output
		for(string val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
