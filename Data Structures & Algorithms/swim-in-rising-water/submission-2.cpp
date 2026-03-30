class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
        minHeap.push({grid[0][0],{0,0}});
        int ans=grid[0][0],n=grid.size(),m=grid[0].size();
        vector<vector<int>> VIS(n,vector<int>(m,0));
        while(!minHeap.empty()) {
            pair<int,pair<int,int>> p=minHeap.top();
            int x=p.second.first,y=p.second.second;
            minHeap.pop();
            ans=max(ans,grid[x][y]);
            VIS[x][y]=1;
            if(x==n-1 && y==m-1)
                break;
            if(x+1<n && VIS[x+1][y]==0)
                minHeap.push({grid[x+1][y],{x+1,y}});
            if(x-1>=0 && VIS[x-1][y]==0)
                minHeap.push({grid[x-1][y],{x-1,y}});
            if(y+1<m && VIS[x][y+1]==0)
                minHeap.push({grid[x][y+1],{x,y+1}});
            if(y-1>=0 && VIS[x][y-1]==0)
                minHeap.push({grid[x][y-1],{x,y-1}});
        }
        return ans;
    }
};
