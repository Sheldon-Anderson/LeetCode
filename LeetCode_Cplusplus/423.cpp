#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        if(!s.length()){
			return "";
		}
		// count
		int *count = new int[26];
		int *mark = new int[10];
		memset(count, 0, sizeof(int) * 26);
		memset(mark, 0, sizeof(int) * 10);
		for(char c: s){
			count[c - 'a']++;
		}
		// get answer
		// 0->2->4->6->8->1->3->5->7->9
		// z->w->u->x->g->o->t->f->v->i/e/2n
		int cnt = count['z' - 'a'];
		if(cnt){
			mark[0] = cnt;
			count['z' - 'a'] -= cnt;
			count['e' - 'a'] -= cnt;
			count['r' - 'a'] -= cnt;
			count['o' - 'a'] -= cnt;
		}
		cnt = count['w' - 'a'];
		if(cnt){
			mark[2] = cnt;
			count['t'- 'a'] -= cnt;
			count['w'- 'a'] -= cnt;
			count['o'- 'a'] -= cnt;
		}
		cnt = count['u' - 'a'];		
		if(cnt){
			mark[4] = cnt;
			count['f'- 'a'] -= cnt;
			count['o'- 'a'] -= cnt;
			count['u'- 'a'] -= cnt;
			count['r'- 'a'] -= cnt;
		}
		cnt = count['x' - 'a'];
		if(cnt){
			mark[6] = cnt;
			count['s'- 'a'] -= cnt;
			count['i'- 'a'] -= cnt;
			count['x'- 'a'] -= cnt;
		}
		cnt = count['g' - 'a'];
		if(cnt){
			mark[8] = cnt;
			count['e'- 'a'] -= cnt;
			count['i'- 'a'] -= cnt;
			count['g'- 'a'] -= cnt;
			count['h'- 'a'] -= cnt;
			count['t'- 'a'] -= cnt;
		}
		cnt = count['o' - 'a'];
		if(cnt){
			mark[1] = cnt;
			count['o'- 'a'] -= cnt;
			count['n'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
		}
		cnt = count['t' - 'a'];
		if(cnt){
			mark[3] = cnt;
			count['t'- 'a'] -= cnt;
			count['h'- 'a'] -= cnt;
			count['r'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
		}
		cnt = count['f' - 'a'];
		if(cnt){
			mark[5] = cnt;
			count['f'- 'a'] -= cnt;
			count['i'- 'a'] -= cnt;
			count['v'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
		}
		cnt = count['v' - 'a'];
		if(cnt){
			mark[7] = cnt;
			count['s'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
			count['v'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
			count['n'- 'a'] -= cnt;
		}
		cnt = count['e' - 'a'];
		if(cnt){
			mark[9] = cnt;
			count['n'- 'a'] -= cnt;
			count['i'- 'a'] -= cnt;
			count['n'- 'a'] -= cnt;
			count['e'- 'a'] -= cnt;
		}
		string ans = "";
		for(int i = 0; i <= 9; i++){
			if(mark[i]){
				ans += string(mark[i], i + '0');
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.originalDigits(s) << endl;
	}
	return 0;
}
