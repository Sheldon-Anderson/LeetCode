#include <bits/stdc++.h>

using namespace std;

#define LL long long

/*
	lower <= sum(i, j) <= upper, 0 <= i <= j <= n - 1
	=>  lower <= sum(j) - sum(i - 1) <= upper
	=>  lower + sum(i - 1) <= sum(j) <= upper + sum(i - 1)
	=>  lower - 1 + sum(i - 1) < sum(j) <= upper + sum(i - 1)
*/

/*
// segment tree
// Accepted
class Solution {
private: 
	int *sum;
	
	// compare function
	static int cmp(const LL a, const LL b){
		return a < b;
	}
	
	// update from down to up
	void PushUp(int rt){
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}

	// build
	void build(int l, int r, int rt){
		if(l == r){
			sum[rt] = 0;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		PushUp(rt);
	}
	
	// update the val at pos
	void update_add(int pos, int val, int l, int r, int rt){
		if(l == r){
			sum[rt] += val;
			return;
		}
		int m = (l + r) >> 1;
		if(pos <= m){
			update_add(pos, val, l, m, rt << 1);
		}
		else{
			update_add(pos, val, m + 1, r, rt << 1 | 1);
		}
		PushUp(rt);
	}
	
	// get sum between L and R
	int query_sum(int L, int R, int l, int r, int rt){
		if(L <= l && r <= R){
			return sum[rt];
		}
		int m = (l + r) >> 1;
		int ret = 0;
		if(L <= m){
			ret += query_sum(L, R, l, m, rt << 1);
		}
		if(R > m){
			ret += query_sum(L, R, m + 1, r, rt << 1 | 1);
		}
		return ret;
	}

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		int N = nums.size();
        if(!N){
			return 0;
		}
		// assign sums
		// for case: vector<int> nums = {-2147483647, 0, -2147483647, 2147483647};	int lower = -564, upper = 3864;
		LL S = 0;
		vector<LL> sums;
		sums.push_back((LL)(lower - 1));
		sums.push_back((LL)upper);
		for(int val: nums){
			S += (LL)val;
			sums.push_back((LL)S);
			sums.push_back((LL)(S + lower - 1));
			sums.push_back((LL)(S + upper));
		}
		// sort
		sort(sums.begin(), sums.end(), cmp);
		// discretization
		auto start = sums.begin(), end = unique(sums.begin(), sums.end());
		map<LL, int> m;
		int index = 1;
		for(; start != end; start++, index++){
			m[*start] = index;
		}
		// create, build and init the segment tree
		int n = index - 1;
		sum = new int[(n + 1) << 2];
		build(1, n, 1);
		// update
		int ans = 0;
		for(int i = N - 1; i >= 0; i--){
			update_add(m[S], 1, 1, n, 1);
			S -= (LL)nums[i];
			ans += (query_sum(1, m[S + (LL)upper], 1, n, 1) - query_sum(1, m[S + (LL)(lower - 1)], 1, n, 1));
		}
		// get answer
		return ans;
    }
};
*/

// binary indexed tree
class Solution{
private: 
	int n;
	int *bit;
	
	// compare function
	static int cmp(const LL a, const LL b){
		return a < b;
	}

	int lowestbit(int i){
		return i & (-i);
	}
	
	// get sum between 1 and i
	int sum(int i){
		int s = 0;
		while(i > 0){
			s += bit[i];
			i -= lowestbit(i);
		}
		return s;
	}
	
	// add x at i
	void add(int i, int x){
		while(i <= n){
			bit[i] += x;
			i += lowestbit(i);
		}
	}

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		int N = nums.size();
		if(!N){
			return 0;
		}
		// assign sums
		LL S = 0;
		vector<LL> sums;
		sums.push_back((LL)(lower - 1));
		sums.push_back((LL)upper);
		for(int val: nums){
			S += (LL)val;
			sums.push_back(S);
			sums.push_back(S + (LL)(lower - 1));
			sums.push_back(S + (LL)upper);
		}
		// sort
		sort(sums.begin(), sums.end());
		auto start = sums.begin(), end = unique(sums.begin(), sums.end());
		// discretization
		map<LL, int> m;
		int index = 1;
		for(; start != end; start++, index++){
			m[*start] = index;
		}
		// create and init the BIT
		n = index - 1;
		bit = new int[n + 1];
		memset(bit, 0, sizeof(int) * (n + 1));
		// update the BIT
		int ans = 0;
		for(int i = N - 1; i >= 0; i--){
			add(m[S], 1);
			S -= (LL)nums[i];
			ans += (sum(m[S + (LL)upper]) - sum(m[S + (LL)(lower - 1)]));
		}
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {-2147483647, 0, -2147483647, 2147483647};
	int lower = -564, upper = 3864;
	cout << "ans: " << sol.countRangeSum(nums, lower, upper) << endl;
	return 0;
}
