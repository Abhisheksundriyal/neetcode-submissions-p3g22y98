class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> graph(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;
    unordered_set<int> VIS;
    int ans=0;
    for(int i=0;i<times.size();i++)
    {
        int u=times[i][0],v=times[i][1],t=times[i][2];
        graph[u].push_back({v,t});
        // graph[v].push_back({u,t});
    }
    que.push({0,k});
    while(!que.empty())
    {
        pair<int,int> p=que.top();
        que.pop();
        if(VIS.find(p.second)!=VIS.end())
            continue;
        // cout<<"p: "<<p.first<<" "<<p.second<<"\n";
        VIS.insert(p.second);
        ans=max(ans,p.first);
        for(int i=0;i<graph[p.second].size();i++)
        {
            pair<int,int> temp=graph[p.second][i];
            que.push({p.first+temp.second,temp.first});
        }
    }
    if(VIS.size()!=n)
        return -1;
    return ans;
}
};
