class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0)
                    que.push({i,j});
            }
        }
        while(!que.empty())
        {
            pair<int,int> p=que.front();
            que.pop();
            if(p.first+1<n && grid[p.first+1][p.second]>grid[p.first][p.second]+1)
            {
                que.push({p.first+1,p.second});
                grid[p.first+1][p.second]=grid[p.first][p.second]+1;
            }
            if(p.first-1>=0 && grid[p.first-1][p.second]>grid[p.first][p.second]+1)
            {
                que.push({p.first-1,p.second});
                grid[p.first-1][p.second]=grid[p.first][p.second]+1;
            }
            if(p.second+1<m && grid[p.first][p.second+1]>grid[p.first][p.second]+1)
            {
                que.push({p.first,p.second+1});
                grid[p.first][p.second+1]=grid[p.first][p.second]+1;
            }
            if(p.second-1>=0 && grid[p.first][p.second-1]>grid[p.first][p.second]+1)
            {
                que.push({p.first,p.second-1});
                grid[p.first][p.second-1]=grid[p.first][p.second]+1;
            }
        }
    }
};
