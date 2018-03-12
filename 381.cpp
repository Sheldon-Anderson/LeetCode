#include <bits/stdc++.h>

using namespace std;

// map + vector + rand()
class RandomizedCollection {
private: 
	// map from val to its corresponding indices in vec
	map<int, vector<int>> m;
	// first: val, second: its corresponding index in m[val]
	vector<pair<int, int>> vec;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].emplace_back(vec.size());
		vec.emplace_back(make_pair(val, m[val].size() - 1));
		return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)){
			return false;
		}
		pair<int, int> v_back = vec.back();
		m[v_back.first][v_back.second] = m[val].back();
		vec[m[val].back()] = v_back;
		m[val].pop_back();
		if(!m[val].size()){
			m.erase(val);
		}
		vec.pop_back();
		return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(!vec.size()){
			return -1;
		}
		return vec[rand() % vec.size()].first;
    }
};

int main(int argc, char** argv){
	// Init an empty collection.
	RandomizedCollection collection;

	// Inserts 1 to the collection. Returns true as the collection did not contain 1.
	cout << "insert: " << collection.insert(1) << endl;

	// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
	cout << "insert: " << collection.insert(1) << endl;

	// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
	cout << "insert: " << collection.insert(2) << endl;

	// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
	cout << "getRandom: " << collection.getRandom() << endl;

	// Removes 1 from the collection, returns true. Collection now contains [1,2].
	cout << "remove: " << collection.remove(1) << endl;

	// getRandom should return 1 and 2 both equally likely.
	cout << "getRandom: " << collection.getRandom() << endl;
	return 0;
}
