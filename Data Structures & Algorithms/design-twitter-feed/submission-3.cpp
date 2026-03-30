class Twitter {
public:
    unordered_map<int,unordered_set<int>> user;
    unordered_map<int,queue<pair<int,int>>> tweet;
    int N;

    Twitter() {
        user.clear();
        tweet.clear();
        N=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push({N,tweetId});
        if(tweet[userId].size()>10)
            tweet[userId].pop();
        N++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        for(auto itr=user[userId].begin();itr!=user[userId].end();++itr)
        {
            int temp=(*itr);
            if(temp==userId)
                count=1;
            queue<pair<int,int>> que=tweet[temp];
            while(!que.empty())
            {
                minHeap.push(que.front());
                if(minHeap.size()>10)
                    minHeap.pop();
                que.pop();
            }
        }
        if(count==0)
        {
            int temp=userId;
            queue<pair<int,int>> que=tweet[temp];
            while(!que.empty())
            {
                minHeap.push(que.front());
                if(minHeap.size()>10)
                    minHeap.pop();
                que.pop();
            }
        }
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user[followerId].erase(followeeId);
    }
};
