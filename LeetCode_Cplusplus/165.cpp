#include<bits/stdc++.h>
using namespace std;

// istringstream
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1);
		istringstream iss2(version2);
		stringstream stream;
		vector<int> v1, v2;
		string str1 = "", str2 = "";
		int num;
		while(getline(iss1, str1, '.')){
			stream << str1;
			stream >> num;
			stream.clear();
			v1.push_back(num);
		}
		while(getline(iss2, str2, '.')){
			stream << str2;
			stream >> num;
			stream.clear();
			v2.push_back(num);
		}
		int n1 = v1.size(), n2 = v2.size();
		// add zeros to the end to make sure n1 == n2
		if(n1 > n2){
			for(int i = 1; i <= n1 - n2; i++){
				v2.push_back(0);
			}
		}
		else if(n1 < n2){
			for(int i = 1; i <= n2 - n1; i++){
				v1.push_back(0);
			}
		}
		for(int i = 0; i <= max(n1, n2) - 1; i++){
			if(v1[i] < v2[i]){
				return -1;
			}
			else if(v1[i] > v2[i]){
				return 1;
			}
		}
		return 0;
    }
};

int main(){
	Solution sol;
	string version1, version2;
	while(cin >> version1 >> version2){
		cout << "ans: " << sol.compareVersion(version1, version2) << endl;
	}
	return 0;
}
