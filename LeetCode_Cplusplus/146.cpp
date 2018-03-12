#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private: 
	int cap;
	list<pair<int, int>> l;
	map<int, list<pair<int, int>>::iterator> m;
	list<pair<int, int>>::iterator ite_list;
	map<int, list<pair<int, int>>::iterator>::iterator ite_map;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        ite_map = m.find(key);
		if(ite_map != m.end()){
			l.push_front(*ite_map->second);
			l.erase(ite_map->second);
			ite_map->second = l.begin();
			return ite_map->second->second;
		}
		return -1;
    }
    
    void put(int key, int value) {
		ite_map = m.find(key);
        if(ite_map != m.end()){
			l.push_front(*ite_map->second);
			l.erase(ite_map->second);
			ite_map->second = l.begin();
			ite_map->second->second = value;
		}
		else{
			if(l.size() == cap){
				m.erase(l.crbegin()->first);
				l.pop_back();
			}
			l.push_front(make_pair(key, value));
			m[key] = l.begin();
		}
    }
	
	// test
	void output(){
		for(ite_list = l.begin(); ite_list != l.end(); ite_list++){
			cout << "(" << ite_list->first << ", " << ite_list->second << ")" << " ";
		}
		cout << endl;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
int main(){
	int capacity = 3;
	vector<pair<int, int>> list = {{2, 2},{3, 3},{2, 2},{1, 1},{5, 5},{2, 2},{4, 4},{5, 5},{3, 3},{2, 2},{5, 5},{2, 2}};
	LRUCache lc(capacity);
	// put
	cout << "put: " << endl;
	for(auto p: list){
		cout << "key: " << p.first << ", value: " << p.second << endl;
		lc.put(p.first, p.second);
		lc.output();
		cout << endl << endl;
	}
	// get
	cout << "get: " << endl;
	list.push_back(make_pair(10, 10));
	for(int i = 10; i <= list.size() - 1; i++){
		cout << "key: " << list[i].first << ", value: " << list[i].second << endl;
		cout << "get: " << lc.get(list[i].first) << endl;
		lc.output();
		cout << endl << endl;
	}
	return 0;
}
