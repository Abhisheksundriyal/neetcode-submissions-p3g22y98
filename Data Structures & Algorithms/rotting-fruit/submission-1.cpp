class Solution {
public:
    void recur(vector<vector<int>>& grid,queue<pair<int,int>> que,int& count,int& ans) {
        if(count==0 || que.empty())
            return;
        ans++;
        queue<pair<int,int>> newQue;
        while(!que.empty())
        {
            int x=que.front().first,y=que.front().second;
            que.pop();
            if(x+1<grid.size() && grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                newQue.push({x+1,y});
            }
            if(x-1>=0 && grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                newQue.push({x-1,y});
            }
                
            if(y+1<grid[0].size() && grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                newQue.push({x,y+1});
            }
                
            if(y-1>=0 && grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                newQue.push({x,y-1});
            } 
        }
        count-=newQue.size();
        recur(grid,newQue,count,ans);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int ans=0,count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1)
                    count++;
                if(grid[i][j]==2)
                    que.push({i,j});
            }
        }
        recur(grid,que,count,ans);
        if(count>0)
            return -1;
        return ans;
    }
};