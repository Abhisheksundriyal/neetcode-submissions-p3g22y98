class Solution {
public:
    void bfs(vector<vector<int>>& grid,int n,int m,queue<pair<int,int>>& myQue) {
    if(myQue.empty())
        return;
    pair<int,int> p=myQue.front();
    myQue.pop();
    if(p.first+1<n && grid[p.first+1][p.second]>(grid[p.first][p.second]+1))
    {
        grid[p.first+1][p.second]=(grid[p.first][p.second]+1);
        myQue.push({p.first+1,p.second});
    }
    if(p.first-1>=0 && grid[p.first-1][p.second]>(grid[p.first][p.second]+1))
    {
        grid[p.first-1][p.second]=(grid[p.first][p.second]+1);
        myQue.push({p.first-1,p.second});
    }
    if(p.second+1<m && grid[p.first][p.second+1]>(grid[p.first][p.second]+1))
    {
        grid[p.first][p.second+1]=(grid[p.first][p.second]+1);
        myQue.push({p.first,p.second+1});
    }
    if(p.second-1>=0 && grid[p.first][p.second-1]>(grid[p.first][p.second]+1))
    {
        grid[p.first][p.second-1]=(grid[p.first][p.second]+1);
        myQue.push({p.first,p.second-1});
    }
    bfs(grid,n,m,myQue);
}

void islandsAndTreasure(vector<vector<int>>& grid) {
    queue<pair<int,int>> myQue;
    int n=grid.size(),m=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
                myQue.push({i,j});
        }
    }
    bfs(grid,n,m,myQue);
}
};
