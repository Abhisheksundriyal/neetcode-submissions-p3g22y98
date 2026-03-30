class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> mp;
    unordered_set<int> mySet;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        for(int i=0;i<times.size();i++)
        {
            int a=times[i][0],b=times[i][1],t=times[i][2];
            mp[a].push_back({b,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        minHeap.push({0,k});
        while(!minHeap.empty() && mySet.size()<n)
        {
            int t=minHeap.top().first,node=minHeap.top().second;
            ans=t;
            mySet.insert(node);
            minHeap.pop();
            for(int i=0;i<mp[node].size();i++)
            {
                int T=mp[node][i].second,newNode=mp[node][i].first;
                if(mySet.find(newNode)==mySet.end())
                    minHeap.push({ans+T,newNode});
            }
        }
        if(mySet.size()==n)
            return ans;
        return -1;
    }
};
