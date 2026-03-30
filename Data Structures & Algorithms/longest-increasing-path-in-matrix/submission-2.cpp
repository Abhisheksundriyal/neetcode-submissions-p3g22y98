class Solution {
public:
    int recur(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        
        if(dp[i][j]!=0)
            return dp[i][j];
        int ans=1;
        if(i+1<n && matrix[i+1][j]>matrix[i][j])
            ans=max(ans,1+recur(i+1,j,n,m,matrix,dp));
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
            ans=max(ans,1+recur(i-1,j,n,m,matrix,dp));
        if(j+1<m && matrix[i][j+1]>matrix[i][j])
            ans=max(ans,1+recur(i,j+1,n,m,matrix,dp));
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
            ans=max(ans,1+recur(i,j-1,n,m,matrix,dp));
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==0)
                    recur(i,j,n,m,matrix,dp);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};