class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    que.push({i,j});
            }
        }
        while(!que.empty()) {
            int x=que.front().first,y=que.front().second;
            que.pop();
            if(x+1<n && grid[x][y]+1<grid[x+1][y])
            {
                que.push({x+1,y});
                grid[x+1][y]=grid[x][y]+1;
            }
            if(x-1>=0 && grid[x][y]+1<grid[x-1][y])
            {
                que.push({x-1,y});
                grid[x-1][y]=grid[x][y]+1;
            }
            if(y+1<m && grid[x][y]+1<grid[x][y+1])
            {
                que.push({x,y+1});
                grid[x][y+1]=grid[x][y]+1;
            }
            if(y-1>=0 && grid[x][y]+1<grid[x][y-1])
            {
                que.push({x,y-1});
                grid[x][y-1]=grid[x][y]+1;
            }
        }
    }
};
