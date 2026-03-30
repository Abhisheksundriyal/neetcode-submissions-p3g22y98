class Solution {
public:
    int recur(int i,int j,int n,int m,vector<vector<int>>& dp) {
        if(i>=n || i<0 || j>=m || j<0)
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = recur(i+1,j,n,m,dp) + recur(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(0,0,m,n,dp);
    }
};
