#include<bits/stdc++.h>
using namespace std;

// map
class LFUCache {
private: 
	int cap;
	int size;
	int minFre;
	// key -> {value, frequency}
	map<int, pair<int, int>> m1;
	// key -> key list iterator for the same frequency
	map<int, list<int>::iterator> m2;
	// frequency -> key list for the same frequency
	map<int, list<int>> m3;

public:
    LFUCache(int capacity) {
        cap = capacity;
		size = 0;
		minFre = 0;
    }
    
    int get(int key) {
		if(m1.count(key)){
			m3[m1[key].second].erase(m2[key]);
			m1[key].second++;
			m3[m1[key].second].push_back(key);
			m2[key] = --m3[m1[key].second].end();
			// if(!m3.count(minFre)){ if m3 is empty will cause an error!
			if(!m3[minFre].size()){
				minFre++;
			}
			return m1[key].first;
		}
		return -1;
    }
    
    void put(int key, int value) {
        if(cap <= 0){
			return;
		}
		if(get(key) != -1){
			m1[key].first = value;
			return;
		}
		if(size >= cap){
			m1.erase(m3[minFre].front());
			m2.erase(m3[minFre].front());
			m3[minFre].pop_front();
			size--;
		}
		m1[key] = {value, 1};
		m3[1].push_back(key);
		m2[key] = --m3[1].end();
		minFre = 1;
		size++;
    }
	
	// test
	// void output(){
		// for(auto &p: m1){
			// cout << "key: " << p.first << ", value: " << p.second.first << ", fre: " << p.second.second << endl;
		// }
		// cout << endl;
	// }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
	int capacity = 3;
	vector<pair<int, int>> list = {{2, 2},{3, 3},{2, 2},{1, 1},{5, 5},{2, 2},{4, 4},{5, 5},{3, 3},{2, 2},{5, 5},{2, 2}};	
	LFUCache lc(capacity);
	// put
	cout << "put: " << endl;
	for(auto &p: list){
		cout << "key: " << p.first << ", value: " << p.second << endl;
		lc.put(p.first, p.second);
		lc.output();
	}
	// get
	cout << "get: " << endl;
	list.push_back(make_pair(10, 10));
	for(int i = 10; i <= list.size() - 1; i++){
		cout << "key: " << list[i].first << ", value: " << list[i].second << endl;
		cout << "get: " << lc.get(list[i].first) << endl;
		lc.output();
	}
	return 0;
}
