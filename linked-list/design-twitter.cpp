class Twitter {
private:
    int timestamp = 0;
public:
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollowing;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timestamp++});
    }
    
    vector<int> getNewsFeed(int userId) {
        follow(userId, userId);
        priority_queue<vector<int>> pq;

        for(auto& following : userFollowing[userId]){
            //here i will get a lot of lists including users own list
            auto& tweets = userTweets[following];
            if(!tweets.empty()){
                int i = tweets.size() - 1;
                pq.push({tweets[i].second, tweets[i].first, following, i});
            }
        }
        vector<int> result;
        while(!pq.empty() && result.size() < 10){
            auto top = pq.top();
            pq.pop();
            int time = top[0];
            int tweetId = top[1];
            int followee = top[2];
            int index = top[3];
            result.push_back(tweetId);        

            if(index > 0){
                auto& tweets = userTweets[followee];
                pq.push({tweets[index-1].second, tweets[index-1].first, followee, index-1});
            }
        }
        unfollow(userId, userId);

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
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