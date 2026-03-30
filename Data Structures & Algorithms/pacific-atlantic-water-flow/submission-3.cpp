class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& o,vector<vector<int>>& heights) {
    o[i][j]=1;
    if(i+1<heights.size() && heights[i+1][j]>=heights[i][j] && o[i+1][j]==0)
        dfs(i+1,j,o,heights);
    if(i-1>=0 && heights[i-1][j]>=heights[i][j] && o[i-1][j]==0)
        dfs(i-1,j,o,heights);
    if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j] && o[i][j+1]==0)
        dfs(i,j+1,o,heights);
    if(j-1>=0 && heights[i][j-1]>=heights[i][j] && o[i][j-1]==0)
        dfs(i,j-1,o,heights);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n=heights.size(),m=heights[0].size();
    vector<vector<int>> ans,a(n,vector<int>(m,0)),p=a;
    for(int i=0;i<n;i++)
    {
        p[i][0]=1;
        a[i][m-1]=1;
    }
    for(int j=0;j<m;j++)
    {
        p[0][j]=1;
        a[n-1][j]=1;
    }
    for(int i=0;i<n;i++)
    {
        dfs(i,0,p,heights);
        dfs(i,m-1,a,heights);
    }
    for(int j=0;j<m;j++)
    {
        dfs(0,j,p,heights);
        dfs(n-1,j,a,heights);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]+p[i][j]==2)
                ans.push_back({i,j});
        }
    }
    return ans;
}
};
