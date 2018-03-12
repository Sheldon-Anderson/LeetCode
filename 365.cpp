#include <bits/stdc++.h>
using namespace std;

// m * x + n * y = z, x, y, z∈N+, m, n ∈Z
// There exists m, n <=> z % gcd(x, y) == 0
class Solution {
private: 	
	int gcd(int a, int b){
		if(!(a % b)){
			return b;
		}
		return gcd(b, a % b);
	}

public:
    bool canMeasureWater(int x, int y, int z) {
		// Exceptional Case: 
        if(z == 0){
			return true;
		}
		if(x == 0 || y == 0){
			return x + y == z;
		}
		return z % gcd(x, y) == 0 && x + y >= z;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int x, y, z;
	while(cin >> x >> y >> z){
		cout << "ans: " << sol.canMeasureWater(x, y, z) << endl;
	}
	return 0;
}
