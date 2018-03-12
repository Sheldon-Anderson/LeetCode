#include <bits/stdc++.h>
using namespace std;

/*
// segment tree
// Accepted
class NumArray {
private: 
	int *A, *sum;
	int n;
	
	// update from down to top
	void PushUp(int rt){
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}

	// build the segment tree
	void build(int l, int r, int rt){
		if(l == r){
			sum[rt] = A[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
		PushUp(rt);
	}
	
	// update the value at pos
	void update_rep(int pos, int val, int l, int r, int rt){
		if(l == r){
			sum[rt] = val;
			return;
		}
		int m = (l + r) >> 1;
		if(pos <= m){
			update_rep(pos, val, l, m, rt << 1);
		}
		else{
			update_rep(pos, val, m + 1, r, rt << 1 | 1);
		}
		PushUp(rt);
	}
	
	// get the sum between L and R
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
    NumArray(vector<int> nums) {
        n = nums.size();
		if(n != 0){
			// create
			A = new int[n + 1];
			sum = new int[(n + 1) << 2];
			for(int i = 1; i <= n; i++){
				A[i] = nums[i - 1];
			}
			// build (init)
			build(1, n, 1);
		}
    }
    
    void update(int i, int val) {
        update_rep(++i, val, 1, n, 1);
    }
    
    int sumRange(int i, int j) {
        return query_sum(++i, ++j, 1, n, 1);
    }
};
*/

// binary indexed tree
class NumArray {
private: 
	int *A, *bit;
	int n;
	
	int lowestbit(int i){
		return i & (-i);
	}
	
	// update the val at pos
	void update_add(int i, int val){
		while(i <= n){
			bit[i] += val;
			i += lowestbit(i);
		}
	}
	
	// get the sum between 1 and i
	int query_sum(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= lowestbit(i);
		}
		return ret;
	}
	
public:
    NumArray(vector<int> nums) {
		n = nums.size();
		if(n > 0){
			// create and init
			A = new int[n + 1];
			bit = new int[n + 1];
			memset(bit, 0, sizeof(int) * (n + 1));
			for(int i = 1; i <= n; i++){
				A[i] = nums[i - 1];
				update_add(i, A[i]);
			}
		}
    }
    
    void update(int i, int val) {
		i++;
		update_add(i, val - A[i]);
		A[i] = val;
    }
    
    int sumRange(int i, int j) {
		return query_sum(++j) - query_sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
  
int main(int argc, char** argv){
	vector<int> nums = {1, 3, 5};
	NumArray na(nums);
	cout << "ans: " << na.sumRange(0, 2) << endl;
	na.update(1, 2);
	cout << "ans: " << na.sumRange(0, 2) << endl;
	return 0;
}
