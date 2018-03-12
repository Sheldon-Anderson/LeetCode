#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int Area = (C - A) * (D - B) + (G - E) * (H - F);
        if(A >= G || C <= E || B >= H || D <= F){
			return Area;
		}
		vector<int> X = {A, C, E, G};
		vector<int> Y = {B, D, F, H};
		sort(X.begin(), X.end(), cmp);
		sort(Y.begin(), Y.end(), cmp);
		return Area - (X[2] - X[1]) * (Y[2] - Y[1]);
    }
};

int main(){
	Solution sol;
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	cout << "ans: " << sol.computeArea(A, B, C, D, E, F, G, H) << endl;
	return 0;
}
