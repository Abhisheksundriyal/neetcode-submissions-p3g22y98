class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> VIS(n+1,0);
    int ans=0,count=0;
    for(int i=0;i<times.size();i++)
        graph[times[i][0]].push_back({times[i][2],times[i][1]});
    minHeap.push({0,k});
    while(!minHeap.empty())
    {
        pair<int,int> p=minHeap.top();
        minHeap.pop();
        if(VIS[p.second]==1)
            continue;
        VIS[p.second]=1;
        count++;
        ans=p.first;
        for(int i=0;i<graph[p.second].size();i++)
        {
            pair<int,int> next=graph[p.second][i];
            if(VIS[next.second]==0)
                minHeap.push({next.first+ans,next.second});
        }
    }
    if(count<n)
        return -1;
    return ans;
}
};
