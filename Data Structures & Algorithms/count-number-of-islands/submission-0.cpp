class Solution {
public:

    void recur(vector<vector<char>>& grid,int i,int j) {
        grid[i][j]='0';
        if(i+1<grid.size() && grid[i+1][j]=='1')
            recur(grid,i+1,j);
        if(i-1>=0 && grid[i-1][j]=='1')
            recur(grid,i-1,j);
        if(j+1<grid[i].size() && grid[i][j+1]=='1')
            recur(grid,i,j+1);
        if(j-1>=0 && grid[i][j-1]=='1')
            recur(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int m=grid[i].size();
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    recur(grid,i,j);
                }
            }
        }
        return ans;
    }
};
