// BFS + priority_queue
// similar to 42. Trapping Rain Water
class Solution {
private: 
	// directions
	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	// priority_queue compare struct: increase
	struct cmp{
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
			return a.first > b.first;
		}
	};

	int BFS(vector<vector<int>>& heightMap, int m, int n){
		// mark
		vector<vector<bool>> mark(m, vector<bool>(n, false));
		// priority_queue: from the borders
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for(int i = 0; i <= m - 1; i++){
			mark[i][0] = true;
			mark[i][n - 1] = true;
			pq.push(make_pair(heightMap[i][0], i * n + 0));
			pq.push(make_pair(heightMap[i][n - 1], i * n + (n - 1)));
		}
		for(int i = 1; i <= n - 2; i++){
			mark[0][i] = true;
			mark[m - 1][i] = true;
			pq.push(make_pair(heightMap[0][i], 0 * n + i));
			pq.push(make_pair(heightMap[m - 1][i], (m - 1) * n + i));
		}
		// BFS
		int ans = 0;
		pair<int, int> p, pp;
		while(!pq.empty()){
			p = pq.top();
			pq.pop();
			int x = p.second / n, y = p.second % n;
			for(int i = 0; i <= 3; i++){
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];
				// check
				if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && !mark[xx][yy]){
					if(p.first > heightMap[xx][yy]){
                        ans += (p.first - heightMap[xx][yy]);
					}				    
					mark[xx][yy] = true;
					pp.first = max(p.first, heightMap[xx][yy]);
					pp.second = xx * n + yy;
					pq.push(pp);
				}
			}
		}
		return ans;
	}

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
		// Exceptional Case: 
        int m = heightMap.size();
		if(m <= 1){
			return 0;
		}
		int n = heightMap[0].size();
		if(n <= 1){
			return 0;
		}
		// get answer
		return BFS(heightMap, m, n);
    }
};
