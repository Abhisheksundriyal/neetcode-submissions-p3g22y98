class Solution {
public:
    void recurP(vector<vector<int>>& heights,int n,int m,int i,int j,vector<vector<int>>& pacific) {
    pacific[i][j]=-1;
    if(i==0 || j==0)
        pacific[i][j]=1;
    if(i+1<n && heights[i+1][j]<=heights[i][j])
    {
        if(pacific[i+1][j]==-2)
            recurP(heights,n,m,i+1,j,pacific);
        if(pacific[i+1][j]==1)
            pacific[i][j]=1;
    }
    if(i-1>=0 && heights[i-1][j]<=heights[i][j])
    {
        if(pacific[i-1][j]==-2)
            recurP(heights,n,m,i-1,j,pacific);
        if(pacific[i-1][j]==1)
            pacific[i][j]=1;
    }
    if(j+1<m && heights[i][j+1]<=heights[i][j])
    {
        if(pacific[i][j+1]==-2)
            recurP(heights,n,m,i,j+1,pacific);
        if(pacific[i][j+1]==1)
            pacific[i][j]=1;
    }
    if(j-1>=0 && heights[i][j-1]<=heights[i][j])
    {
        if(pacific[i][j-1]==-2)
            recurP(heights,n,m,i,j-1,pacific);
        if(pacific[i][j-1]==1)
            pacific[i][j]=1;
    }
}

void recurA(vector<vector<int>>& heights,int n,int m,int i,int j,vector<vector<int>>& atlantic) {
    atlantic[i][j]=-1;
    if(i==n-1 || j==m-1)
        atlantic[i][j]=1;
    if(i+1<n && heights[i+1][j]<=heights[i][j])
    {
        if(atlantic[i+1][j]==-2)
            recurA(heights,n,m,i+1,j,atlantic);
        if(atlantic[i+1][j]==1)
            atlantic[i][j]=1;
    }
    if(i-1>=0 && heights[i-1][j]<=heights[i][j])
    {
        if(atlantic[i-1][j]==-2)
            recurA(heights,n,m,i-1,j,atlantic);
        if(atlantic[i-1][j]==1)
            atlantic[i][j]=1;
    }
    if(j+1<m && heights[i][j+1]<=heights[i][j])
    {
        if(atlantic[i][j+1]==-2)
            recurA(heights,n,m,i,j+1,atlantic);
        if(atlantic[i][j+1]==1)
            atlantic[i][j]=1;
    }
    if(j-1>=0 && heights[i][j-1]<=heights[i][j])
    {
        if(atlantic[i][j-1]==-2)
            recurA(heights,n,m,i,j-1,atlantic);
        if(atlantic[i][j-1]==1)
            atlantic[i][j]=1;
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n=heights.size(),m=heights[0].size();
    vector<vector<int>> ans;
    vector<vector<int>> pacific(n),atlantic(n);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,-2);
        pacific[i]=temp;
        atlantic[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(pacific[i][j]==-2)
                recurP(heights,n,m,i,j,pacific);
            if(atlantic[i][j]==-2)
                recurA(heights,n,m,i,j,atlantic);
            if(pacific[i][j]==1 && atlantic[i][j]==1)
                ans.push_back({i,j});
        }
    }
    return ans;
}
};
