class Solution {
public:
    bool recur(string& s,vector<pair<char,int>>& V,int n,int m,int i,int j,vector<vector<int>>& dp) {
    if(i==n || j==m)
    {
        dp[i][j]=-1;
        if(i==n && j==m)
            dp[i][j]=1;
        if(i==n && V[j].second==2 && recur(s,V,n,m,i,j+1,dp))
            dp[i][j]=1;
    }
    if(dp[i][j]!=0)
        return (dp[i][j]==1);

    if(V[j].second==1)
    {
        dp[i][j]=-1;
        if(s[i]==V[j].first || V[j].first=='.')
        {
            if(recur(s,V,n,m,i+1,j+1,dp))
                dp[i][j]=1;
        }
    }
    else
    {
        if(s[i]==V[j].first || V[j].first=='.')
        {
            dp[i][j]=-1;
            if(recur(s,V,n,m,i+1,j+1,dp) || recur(s,V,n,m,i+1,j,dp) || recur(s,V,n,m,i,j+1,dp))
                dp[i][j]=1;
        }
        else
        {
            dp[i][j]=-1;
            if(recur(s,V,n,m,i,j+1,dp))
                dp[i][j]=1;
        }
    }

    return (dp[i][j]==1);

}

bool isMatch(string s, string p) {
    vector<pair<char,int>> V;
    for(int i=0;i<p.length();i++)
    {
        if(p[i]!='*')
            V.push_back({p[i],1});
        else
            V[V.size()-1].second=2;
    }
    int n=s.length(),m=V.size();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(m+1,0);
        dp[i]=temp;
    }
    return recur(s,V,n,m,0,0,dp);
}
};
