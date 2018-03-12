#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
	bool checkIPv4(string str){
		int digit = 0;
		bool firstZero = (str[0] == '0');
		for(char c: str){
			if(!isdigit(c)){
				return false;
			}
			digit = digit * 10 + (c - '0');
		}
		if((firstZero && str.length() > 1) || (digit < 0 || digit > 255)){
			return false;
		}
		return true;
	}

	bool checkIPv6(string str){
		for(char c: str){
			// if(!isalnum(c)){ will cause an error!
			if(!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))){				
				return false;
			}
		}
		if(str.length() > 4){
			return false;
		}
		return true;
	}

public:
    string validIPAddress(string IP) {
		if(!IP.length()){
			return "Neither";
		}
		istringstream iss(IP);
		string str, ans;
		vector<string> vec;
        if(IP.find(".") == string::npos && IP.find(":") == string::npos){
			return "Neither";
		}
		else if(IP.find(".") != string::npos && IP.find(":") != string::npos){
			return "Neither";
		}
		// IPv4 possible
		else if(IP.find(".") != string::npos){
			// check the first and the last character
			if(*IP.begin() == '.' || IP.back() == '.'){
				return "Neither";
			}
			while(getline(iss, str, '.')){
				if(str == "" || !checkIPv4(str)){
					return "Neither";
				}
				vec.push_back(str);
			}
			ans = (vec.size() == 4)? "IPv4": "Neither";
		}
		// IPv6 possible
		else if(IP.find(":") != string::npos){
			if(*IP.begin() == ':' || IP.back() == ':'){
				return "Neither";
			}
			while(getline(iss, str, ':')){
				if(str == "" || !checkIPv6(str)){
					return "Neither";
				}
				vec.push_back(str);
			}
			ans = (vec.size() == 8)? "IPv6": "Neither";
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string IP;
	while(cin >> IP){
		cout << "ans:" << sol.validIPAddress(IP) << endl;
	}
	return 0;
}
