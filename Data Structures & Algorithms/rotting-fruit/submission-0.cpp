class Solution {
public:

    void bfs(vector<vector<int>>& grid,int n,int m,queue<pair<int,int>>& myQue,int& fresh,int& ans) {
        queue<pair<int,int>> newQue;
        ans++;
        while(!myQue.empty())
        {
            pair<int,int> p=myQue.front();
            myQue.pop();
            int i=p.first,j=p.second;
            if(i+1<n && grid[i+1][j]==1)
            {
                fresh--;
                grid[i+1][j]=2;
                newQue.push({i+1,j});
            }
            if(i-1>=0 && grid[i-1][j]==1)
            {
                fresh--;
                grid[i-1][j]=2;
                newQue.push({i-1,j});
            }
            if(j+1<m && grid[i][j+1]==1)
            {
                fresh--;
                grid[i][j+1]=2;
                newQue.push({i,j+1});
            }
            if(j-1>=0 && grid[i][j-1]==1)
            {
                fresh--;
                grid[i][j-1]=2;
                newQue.push({i,j-1});
            }
        }
        if(!newQue.empty() && fresh>0)
            bfs(grid,n,m,newQue,fresh,ans);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,n=grid.size(),m=grid[0].size(),ans=0;
        queue<pair<int,int>> myQue;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    myQue.push({i,j});
            }
        }
        if(fresh==0)
            return 0;
        bfs(grid,n,m,myQue,fresh,ans);
        if(fresh==0)
            return ans;
        return -1;
    }
};
