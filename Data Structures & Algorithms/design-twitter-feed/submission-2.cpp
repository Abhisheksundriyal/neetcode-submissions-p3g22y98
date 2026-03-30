class Twitter {
public:

    unordered_map<int,unordered_set<int>> users;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;

    Twitter() {
        users.clear();
        tweets.clear();
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        vector<int> ans;
        unordered_set<int>& temp=users[userId];
        int count=0;
        for(auto itr=temp.begin();itr!=temp.end();++itr)
        {
            if((*itr)==userId)
                count=1;
            vector<pair<int,int>>& V=tweets[(*itr)];
            for(int j=0;j<V.size();j++)
            {
                minHeap.push(V[j]);
                if(minHeap.size()>10)
                    minHeap.pop();
            }
        }
        if(count==0)
        {
            vector<pair<int,int>>& V=tweets[userId];
            for(int j=0;j<V.size();j++)
            {
                minHeap.push(V[j]);
                if(minHeap.size()>10)
                    minHeap.pop();
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
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};
