class Solution {
public:
    int recur(vector<vector<int>>& grid,int i,int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return (1+recur(grid,i+1,j)+recur(grid,i-1,j)+recur(grid,i,j+1)+recur(grid,i,j-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    area=max(area,recur(grid,i,j));
            }
        }
        return area;
    }
};
