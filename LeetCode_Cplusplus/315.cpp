#include <bits/stdc++.h>
using namespace std;

/*
// binary indexed tree
// Accepted
class Solution {
private: 
	int n;
	struct data{
		int index;
		int weight;
	};
	int *bit;
	data *d;

	static int cmp(data a, data b){
		if(a.weight != b.weight){
			return a.weight < b.weight;
		}
		return a.index > b.index;
	}
	
	int lowestbit(int i){
		return i & (-i);
	}
	
	int sum(int i){
		int s = 0;
		while(i > 0){
			s += bit[i];
			i -= lowestbit(i);
		}
		return s;
	}
	
	void add(int i, int x){
		while(i <= n){
			bit[i] += x;
			i += lowestbit(i);
		}
	}
	
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts;
		n = nums.size();
		if(n == 0){
			return counts;
		}
		if(n == 1){
			counts.push_back(0);
			return counts;
		}
		// create and init
		bit = new int[n + 1];
		d = new data[n + 1];
		memset(bit, 0, sizeof(int) * (n + 1));
		reverse(nums.begin(), nums.end());
		nums.insert(nums.begin(), 0);
		// discretization (including sort)
		for(int i = 1; i <= n; i++){
			d[i].weight = nums[i];
			d[i].index = i;
		}
		sort(d + 1, d + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			nums[d[i].index] = i;
		}
		// binary indexed tree manipulation
		for(int i = 1; i <= n; i++){
			add(nums[i], 1);
			counts.push_back(sum(nums[i]) - 1);
		}
		reverse(counts.begin(), counts.end());
		return counts;
    }
};
*/

// segment tree
class Solution{
private: 
	struct data{
		int index;
		int weight;
	};
	int *sum;
	data *d;
	
	static int cmp(data a, data b){
		if(a.weight != b.weight){
			return a.weight < b.weight;
		}
		return a.index > b.index;
	}
	
	// update from down to up
	void PushUp(int rt){
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}

	// build the segment tree
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
	
	// addition
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
	
	// sum
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
    vector<int> countSmaller(vector<int>& nums) {
		vector<int> counts;
		int n = nums.size();
		if(n == 0){
			return counts;
		}
		if(n == 1){
			counts.push_back(0);00
			return counts;
		}
		// create and init
		sum = new int[(n + 1) << 2];
		d = new data[n + 1];
		reverse(nums.begin(), nums.end());
		nums.insert(nums.begin(), 0);
		// discretization (including sort)
		for(int i = 1; i <= n; i++){
			d[i].weight = nums[i];
			d[i].index = i;
		}
		sort(d + 1, d + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			nums[d[i].index] = i;
		}
		// segment tree manipulation
		build(1, n, 1);
		for(int i = 1; i <= n; i++){
			update_add(nums[i], 1, 1, n, 1);
			counts.push_back(query_sum(1, nums[i], 1, n, 1) - 1);
		}
		reverse(counts.begin(), counts.end());
		return counts;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {5, 2, 6, 1};
	vector<int> ans = sol.countSmaller(nums);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
