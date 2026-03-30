class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,ans=0,n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    count++;
                else if(grid[i][j]==2)
                    que.push({i,j});
            }
        }
        while(!que.empty() && count>0)
        {
            ans++;
            queue<pair<int,int>> newQue;
            while(!que.empty())
            {
                int x=que.front().first,y=que.front().second;
                que.pop();
                if(x+1<n && grid[x+1][y]==1)
                {
                    count--;
                    newQue.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    count--;
                    newQue.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(y+1<m && grid[x][y+1]==1)
                {
                    count--;
                    newQue.push({x,y+1});
                    grid[x][y+1]=2;
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    count--;
                    newQue.push({x,y-1});
                    grid[x][y-1]=2;
                }
            }
            que=newQue;
        }
        if(count==0)
            return ans;
        return -1;
    }
};
