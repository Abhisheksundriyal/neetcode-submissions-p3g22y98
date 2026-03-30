class Solution {
public:
    int recur(string& s,string& t,vector<vector<int>>& dp,int i,int j,int n,int m) {
    if(i==n)
    {
        if(j==m)
            return dp[i][j]=1;
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==t[j])
        return dp[i][j]=recur(s,t,dp,i+1,j+1,n,m)+recur(s,t,dp,i+1,j,n,m);
    return dp[i][j]=recur(s,t,dp,i+1,j,n,m);
}

int numDistinct(string s, string t) {
    int n=s.length(),m=t.length();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(m+1,-1);
        dp[i]=temp;
    }
    return recur(s,t,dp,0,0,n,m);
}
};
