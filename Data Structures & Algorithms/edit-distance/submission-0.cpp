class Solution {
public:
    int recur(string& word1,string& word2,vector<vector<int>>& dp,int i,int j,int n,int m) {
    if(i==n)
        return dp[i][j]=m-j;
    if(j==m)
        return dp[i][j]=n-i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(word1[i]!=word2[j])
        return dp[i][j]=1+min(recur(word1,word2,dp,i+1,j+1,n,m),min(recur(word1,word2,dp,i+1,j,n,m),recur(word1,word2,dp,i,j+1,n,m)));
    return dp[i][j]=recur(word1,word2,dp,i+1,j+1,n,m);
}

int minDistance(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(m+1,-1);
        dp[i]=temp;
    }
    return recur(word1,word2,dp,0,0,n,m);
}
};
