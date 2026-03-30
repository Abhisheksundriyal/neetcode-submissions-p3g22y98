class Solution {
public:
    void recur(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int n,int m) {
    dp[i][j]=1;
    int large=0;
    if(i+1<n && matrix[i+1][j]>matrix[i][j])
    {
        // cout<<"hello world1\n";
        if(dp[i+1][j]==0)
            recur(matrix,dp,i+1,j,n,m);
        large=max(large,dp[i+1][j]);
    }
    if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
    {
        // cout<<"hello world2\n";
        if(dp[i-1][j]==0)
            recur(matrix,dp,i-1,j,n,m);
        large=max(large,dp[i-1][j]);
    }
    if(j+1<m && matrix[i][j+1]>matrix[i][j])
    {
        // cout<<"hello world3\n";
        if(dp[i][j+1]==0)
            recur(matrix,dp,i,j+1,n,m);
        large=max(large,dp[i][j+1]);
    }
    if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
    {
        // cout<<"hello world4\n";
        if(dp[i][j-1]==0)
            recur(matrix,dp,i,j-1,n,m);
        large=max(large,dp[i][j-1]);
    }
    // cout<<"i: "<<i<<" j: "<<j<<" large: "<<large<<"\n";
    dp[i][j]+=large;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size(),ans=1;
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);
        dp[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==0)
                recur(matrix,dp,i,j,n,m);
            // cout<<"dp["<<i<<"]["<<j<<"]: "<<dp[i][j]<<"\n";
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
};
