#include <bits/stdc++.h>

using namespace std;

/*
// map
// Accepted
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.length();
		if(!n){
			return 0;
		}
		map<int, int> m;
		m[-1] = 0;
		int start, i = 0;
		int level = 0, ans = 0;
		while(i <= n - 1){
			start = i;
			while(i <= n - 1 && input[i] != '\n' && input[i] != '\t'){
				i++;
			}
			if(i >= n || input[i] == '\n'){
				string str = input.substr(start, i - start);
				if(str.find(".") == string::npos){
					m[level] = m[level - 1] + (i - start + 1);
				}
				else{
					ans = max(ans, m[level - 1] + (i - start));
				}
				level = 0;
			}
			else if(input[i] == '\t'){
				level++;
			}
			i++;
		}
		return ans;
    }
};
*/

// STL: str.find(), str.find_last_of(), getline(), istringstream
class Solution {
public:
    int lengthLongestPath(string input) {
		int n = input.length();
		if(!n){
			return 0;
		}
		map<int, int> m;
		m[-1] = 0;
		int level = -1;
		int ans = 0;
		// split by '\n'
		istringstream iss(input);
		string str;
		while(getline(iss, str, '\n')){
			level = str.find_last_of('\t') + 1;
			if(str.find(".") == string::npos){
				m[level] = m[level - 1] + (str.length() - level + 1);
			}
			else{
				ans = max(ans, m[level - 1] + ((int)str.length() - level));
			}
		}
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout << "input: " << input << endl;
	cout << "ans: " << sol.lengthLongestPath(input);
	return 0;
}
