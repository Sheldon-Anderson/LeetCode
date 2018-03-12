#include <bits/stdc++.h>

using namespace std;

// map + vector + rand()
class RandomizedSet {
private: 
	// save the vals
	vector<int> vec;
	// map from val to its index in vec
	map<int, int> m;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)){
			return false;
		}
		m[val] = vec.size();
		vec.emplace_back(val);
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)){
			return false;
		}
		int key_back = vec.back();
		int value_back = m[key_back];
		int value_val = m[val];
		m[key_back] = value_val;
		m.erase(val);
		vec[value_val] = key_back;
		vec.pop_back();
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(!vec.size()){
			return -1;
		}
		return vec[rand() % vec.size()];
    }
};

int main(int argc, char** argv){
	// Init an empty set.
	RandomizedSet randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.
	cout << "insert: " << randomSet.insert(1) << endl;

	// Returns false as 2 does not exist in the set.
	cout << "remove: " << randomSet.remove(2) << endl;

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	cout << "insert: " << randomSet.insert(2) << endl;

	// getRandom should return either 1 or 2 randomly.
	cout << "get random: " << randomSet.getRandom() << endl;

	// Removes 1 from the set, returns true. Set now contains [2].
	cout << "remove: " << randomSet.remove(1) << endl;

	// 2 was already in the set, so return false.
	cout << "insert: " << randomSet.insert(2) << endl;

	// Since 1 is the only number in the set, getRandom always return 1.
	cout << "get random: " << randomSet.getRandom() << endl;	
	return 0;
}
