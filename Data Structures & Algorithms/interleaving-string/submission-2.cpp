class Solution {
public:
    int recur(int i,int j,int idx,int n,int m,int o,
                string& s1, string& s2, string& s3,
                vector<vector<int>>& dp) {
        if(i>=n && j>=m && idx>=o)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        if(i<n && j<m && idx<o && s1[i]==s3[idx] && s2[j]==s3[idx])
        {
            if(recur(i+1,j,idx+1,n,m,o,s1,s2,s3,dp) || recur(i,j+1,idx+1,n,m,o,s1,s2,s3,dp))
                return dp[i][j] = 1;
        }
        else if(i<n && idx<o && s1[i]==s3[idx])
        {
            if(recur(i+1,j,idx+1,n,m,o,s1,s2,s3,dp))
                return dp[i][j] = 1;
        }
        else if(j<m && idx<o && s2[j]==s3[idx])
        {
            if(recur(i,j+1,idx+1,n,m,o,s1,s2,s3,dp))
                return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),o=s3.size();
        if(n+m!=o)
            return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return (recur(0,0,0,n,m,o,s1,s2,s3,dp)==1);
    }
};
