class Solution {
public:

    bool valid(int i,int j,int m,int n) {
        return (i>=0 && i<m && j>=0 && j<n);
    }

    int recur(vector<vector<int>>& dp,int i,int j,int m,int n) {
        if(i==m-1 && j==n-1)
            return 1;
        int ans=0;
        if(valid(i,j+1,m,n))
        {
            if(dp[i][j+1]==0)
                recur(dp,i,j+1,m,n);
            ans+=dp[i][j+1];
        }
        if(valid(i+1,j,m,n))
        {
            if(dp[i+1][j]==0)
                recur(dp,i+1,j,m,n);
            ans+=dp[i+1][j];
        }
        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            dp[i]=temp;
        }
        dp[m-1][n-1]=1;
        return recur(dp,0,0,m,n);
    }
};
