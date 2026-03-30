class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean,int n,int m,int i,int j) {
    ocean[i][j]=true;
    if(i+1<n && heights[i+1][j]>=heights[i][j] && !ocean[i+1][j])
        dfs(heights,ocean,n,m,i+1,j);
    if(i-1>=0 && heights[i-1][j]>=heights[i][j] && !ocean[i-1][j])
        dfs(heights,ocean,n,m,i-1,j);
    if(j+1<m && heights[i][j+1]>=heights[i][j] && !ocean[i][j+1])
        dfs(heights,ocean,n,m,i,j+1);
    if(j-1>=0 && heights[i][j-1]>=heights[i][j] && !ocean[i][j-1])
        dfs(heights,ocean,n,m,i,j-1);
}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n=heights.size(),m=heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));
    for(int i=0;i<n;i++)
    {
        dfs(heights,pacific,n,m,i,0);
        dfs(heights,atlantic,n,m,i,m-1);
    }
    for(int j=0;j<m;j++)
    {
        dfs(heights,pacific,n,m,0,j);
        dfs(heights,atlantic,n,m,n-1,j);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
        }
    }
    return ans;
}
};
