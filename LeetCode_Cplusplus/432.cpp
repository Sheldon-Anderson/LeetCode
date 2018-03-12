#include<bits/stdc++.h>

using namespace std;

// set + map
class AllOne {
private: 
	// set compare struct
	struct cmp{
		bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)const {
			if(p1.second != p2.second){
				return p1.second < p2.second;
			}
			return p1.first < p2.first;			
		}
	};
	
	set<pair<string, int>, cmp> s;
	map<string, int> m;

public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!m.count(key)){
			m[key] = 1;
			s.insert(make_pair(key, 1));
		}
		else{
			int val = m[key]++;
			auto its = s.find(make_pair(key, val));
			s.erase(its);
			s.insert(make_pair(key, val + 1));
		}
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.count(key)){
			int val = m[key]--;
			auto its = s.find(make_pair(key, val));
			s.erase(its);
			if(val == 1){
				m.erase(key);
			}
			else{
				s.insert(make_pair(key, val - 1));
			}
		}
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
		if(!s.size()){
			return "";
		}
        return s.crbegin()->first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
		if(!s.size()){
			return "";
		}		
        return s.cbegin()->first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

int main(int argc, char** argv){
	AllOne ao;
	ao.inc("aaa");
	ao.inc("bbb");
	ao.inc("ccc");
	ao.inc("aaa");
	ao.inc("aaa");
	ao.inc("bbb");
	cout << "max key: " << ao.getMaxKey() << endl;
	cout << "min key: " << ao.getMinKey() << endl;
	ao.dec("aaa");
	ao.dec("bbb");
	ao.dec("ccc");
	cout << "max key: " << ao.getMaxKey() << endl;
	cout << "min key: " << ao.getMinKey() << endl;	
	return 0;
}

