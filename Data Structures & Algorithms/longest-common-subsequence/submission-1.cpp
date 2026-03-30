class Solution {
public:
    int recur(int i,int j,int n,int m,string& text1,string& text2,vector<vector<int>>& dp) {
        if(i==n || j==m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        if(text1[i]==text2[j])
            ans=1+recur(i+1,j+1,n,m,text1,text2,dp);
        
        ans=max(ans,recur(i+1,j,n,m,text1,text2,dp));
        ans=max(ans,recur(i,j+1,n,m,text1,text2,dp));

        return dp[i][j] = ans;

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recur(0,0,n,m,text1,text2,dp);
    }
};
