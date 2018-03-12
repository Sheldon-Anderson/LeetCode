#include <bits/stdc++.h>

using namespace std;

// Map + Design
class Twitter {
private: 
	// followerId -> followeeIds
	map<int, set<int>> m;
	// userId -> tweetId
	vector<pair<int, int>> vec;

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        vec.insert(vec.begin(), make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
		int cnt = 0;
		for(auto p: vec){
			if(p.first == userId || (m.count(userId) && m[userId].count(p.first))){
				ans.push_back(p.second);
				if(++cnt == 10){
					break;
				}
			}
		}
		return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(m.count(followerId) && m[followerId].count(followeeId)){
			m[followerId].erase(followeeId);
		}
    }
};

int main(int argc, char** argv){
	Twitter twitter;

	// User 1 posts a new tweet (id = 5).
	twitter.postTweet(1, 5);

	// User 1's news feed should return a list with 1 tweet id -> [5].
	vector<int> ans1 = twitter.getNewsFeed(1);
	for(int v1: ans1){
		cout << v1 << " ";
	}
	cout << endl;

	// User 1 follows user 2.
	twitter.follow(1, 2);

	// User 2 posts a new tweet (id = 6).
	twitter.postTweet(2, 6);

	// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
	// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
	vector<int> ans2 = twitter.getNewsFeed(1);
	for(int v2: ans2){
		cout << v2 << " ";
	}
	cout << endl;
	
	// User 1 unfollows user 2.
	twitter.unfollow(1, 2);

	// User 1's news feed should return a list with 1 tweet id -> [5],
	// since user 1 is no longer following user 2.
	vector<int> ans3 = twitter.getNewsFeed(1);	
	for(int v3: ans3){
		cout << v3 << " ";
	}
	cout << endl;	
	return 0;
}
