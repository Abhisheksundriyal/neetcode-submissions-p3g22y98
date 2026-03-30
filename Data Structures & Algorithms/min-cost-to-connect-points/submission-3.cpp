class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    int dist(vector<int>& a,vector<int> & b) {
        int ans=(abs(a[0]-b[0])+abs(a[1]-b[1]));
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),count=0,ans=0;
        vector<int> VIS(n,0);
        minHeap.push({0,0});
        while(!minHeap.empty() && count<n) {
            pair<int,int> p=minHeap.top();
            minHeap.pop();
            if(VIS[p.second]==1)
                continue;
            VIS[p.second]=1;
            ans+=p.first;
            for(int i=0;i<n;i++)
            {
                int d=dist(points[i],points[p.second]);
                minHeap.push({d,i});
            }
        }   
        return ans;     
    }
};
