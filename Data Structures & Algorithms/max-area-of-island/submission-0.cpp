class Solution {
public:

    void recur(vector<vector<int>>& grid,int i,int j,int& count) {
        count++;
        grid[i][j]=0;
        if(j+1<grid[i].size() && grid[i][j+1]==1)
            recur(grid,i,j+1,count);
        if(i+1<grid.size() && grid[i+1][j]==1)
            recur(grid,i+1,j,count);
        if(j-1>=0 && grid[i][j-1]==1)
            recur(grid,i,j-1,count);
        if(i-1>=0 && grid[i-1][j]==1)
            recur(grid,i-1,j,count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    recur(grid,i,j,count);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};
