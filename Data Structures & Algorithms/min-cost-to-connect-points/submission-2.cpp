class Solution {
public:
    int dist(vector<int>& p1,vector<int>& p2) {
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans=0,count=0,n=points.size();
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
            ans+=p.first;
            count++;
            for(int i=0;i<n;i++)
                minHeap.push({dist(points[p.second],points[i]),i});
        }
        return ans;
    }
};
