class Solution {
public:
    int dist(vector<int>& V1,vector<int>& V2) {
    return abs(V1[0]-V2[0])+abs(V1[1]-V2[1]);
}


int minCostConnectPoints(vector<vector<int>>& points) {
    int n=points.size(),ans=0,count=0,node=0;
    vector<int> VIS(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    minHeap.push({0,0});
    while(!minHeap.empty() && count<points.size())
    {
        pair<int,int> p=minHeap.top();
        minHeap.pop();
        if(VIS[p.second]==1)
            continue;
        VIS[p.second]=1;
        count++;
        ans+=p.first;
        node=p.second;
        for(int i=0;i<n;i++)
            minHeap.push({dist(points[node],points[i]),i});
    }
    return ans;
}
};
