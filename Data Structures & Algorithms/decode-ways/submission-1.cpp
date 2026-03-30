class Solution {
public:
    bool valid(string& s,int n,int idx)
{
    if(idx+1>=n)
        return false;
    string temp;
    temp.push_back(s[idx]);
    temp.push_back(s[idx+1]);
    // cout<<"stoi: "<<stoi(temp)<<"\n";
    return (stoi(temp)<=26);
}

void recur(string& s,vector<int>& dp,int idx,int n) {
    if(s[idx]=='0')
    {
        dp[idx]=0;
        return;
    }
    if(idx>=n)
    {
        dp[idx]=1;
        return;
    }
    int ans=0;
    if(dp[idx+1]==-1)
        recur(s,dp,idx+1,n);
    ans+=dp[idx+1];
    if(valid(s,n,idx))
    {
        if(dp[idx+2]==-1)
            recur(s,dp,idx+2,n);
        // cout<<"idx: "<<idx<<" hello world\n";
        ans+=dp[idx+2];
    }
    // cout<<"idx: "<<idx<<" ans: "<<ans<<"\n";
    dp[idx]=ans;
}

int numDecodings(string s) {
    int n=s.length();
    vector<int> dp(n+5,-1);
    recur(s,dp,0,n);
    return dp[0];
}

};
