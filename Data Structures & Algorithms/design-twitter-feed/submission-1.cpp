class Twitter {
public:

    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    unordered_map<int,unordered_set<int>> followList;
    unordered_map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> tweetList;
    int tweetCount;

    Twitter() {
        followList.clear();
        tweetList.clear();
        tweetCount=0;
    }

    void addInVect(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap,vector<pair<int,int>>& ans)
    {
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweetCount++;
        tweetList[userId].push({tweetCount,tweetId});
        if(tweetList[userId].size()>10)
            tweetList[userId].pop();
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> ans;
        vector<int> temp;
        unordered_set<int> mySet=followList[userId];
        bool check=false;
        for(auto itr=mySet.begin();itr!=mySet.end();++itr)
        {
            int user=(*itr);
            if(user==userId)
                check=true;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap=tweetList[user];
            addInVect(minHeap,ans);
        }
        if(check==false)
            addInVect(tweetList[userId],ans);
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        int x=10;
        if(ans.size()<10)
            x=ans.size();
        for(int i=0;i<x;i++)
            temp.push_back(ans[i].second);
        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
