// CreateTime: 2019-12-02 00:39:06
class Twitter {
public:
    int cnt = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> connected;

    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt++, tweetId});
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed.
     * Each item in the news feed must be posted by users who the user followed or by the user herself.
     * Tweets must be ordered from most recent to least recent.
     */
    vector<int> getNewsFeed(int userId) {
        auto s = connected[userId];
        s.insert(userId);

        vector<pair<int, int>> posts;
        for (auto uid: s) {
            for (auto post: tweets[uid]) {
                posts.push_back(post);
            }
        }

        sort(posts.rbegin(), posts.rend());

        vector<int> res;
        for (int i = 0; i < 10 && i < posts.size(); i++) {
            res.push_back(posts[i].second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            connected[followerId].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        connected[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
