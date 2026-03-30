class Solution {
public:
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>> VIS(n,vector<int>(m,0));
        minHeap.push({grid[0][0],{0,0}});
        while(!minHeap.empty()) {
            pair<int,pair<int,int>> p=minHeap.top();
            minHeap.pop();
            int x=p.second.first,y=p.second.second;
            if(VIS[x][y]==1)
                continue;
            VIS[x][y]=1;
            ans=max(ans,p.first);
            if(x==n-1 && y==m-1)
                break;
            if(x+1<n)
                minHeap.push({grid[x+1][y],{x+1,y}});
            if(x-1>=0)
                minHeap.push({grid[x-1][y],{x-1,y}});
            if(y+1<m)
                minHeap.push({grid[x][y+1],{x,y+1}});
            if(y-1>=0)
                minHeap.push({grid[x][y-1],{x,y-1}});
        }
        return ans;
    }
};
