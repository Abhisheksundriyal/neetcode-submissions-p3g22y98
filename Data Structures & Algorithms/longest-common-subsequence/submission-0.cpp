class Solution {
public:
    int recur(string& text1,string& text2,vector<vector<int>>& dp,int i,int j,int  n,int m) {
    if(i>=n || j>=m)
        return dp[i][j] = 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(text1[i]==text2[j])
        return dp[i][j]=1+recur(text1,text2,dp,i+1,j+1,n,m);
    return dp[i][j]=max(recur(text1,text2,dp,i+1,j,n,m),recur(text1,text2,dp,i,j+1,n,m));
}

int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size(),m=text2.size();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(m+1,-1);
        dp[i]=temp;
    }
    return recur(text1,text2,dp,0,0,n,m);
}
};
