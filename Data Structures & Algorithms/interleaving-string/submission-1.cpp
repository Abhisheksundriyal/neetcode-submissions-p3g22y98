class Solution {
public:
    bool recur(string& s1,string&s2,string& s3,vector<vector<int>>& dp,int i,int j,int idx) {
    if((s1.length()+s2.length())!=s3.length())
    {
        dp[i][j]=-1;
        return false;
    }
    if(i==s1.length() && j==s2.length() && idx==s3.length())
    {
        dp[i][j]=1;
        return true;
    }

    int ans=-1;

    if(i<s1.length() && s1[i]==s3[idx])
    {
        if(dp[i+1][j]==0)
            recur(s1,s2,s3,dp,i+1,j,idx+1);
        if(dp[i+1][j]==1)
            ans=1;
    }
    if(j<s2.length() && s2[j]==s3[idx])
    {
        if(dp[i][j+1]==0)
            recur(s1,s2,s3,dp,i,j+1,idx+1);
        if(dp[i][j+1]==1)
            ans=1;
    }
    dp[i][j]=ans;
    return (dp[i][j]==1);
}

bool isInterleave(string s1, string s2, string s3) {
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(m+1,0);
        dp[i]=temp;
    }
    return recur(s1,s2,s3,dp,0,0,0);
}
};
