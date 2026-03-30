class Solution {
public:
    int recur(int idx,int n,string& s,vector<int>& dp) {
        if(idx>=n)
            return dp[idx] = 1;
        if(dp[idx]!=-1)
            return dp[idx];
        if(s[idx]=='0')
            return 0;
        int ans1=recur(idx+1,n,s,dp),ans2=0;
        if(idx+1<n)
        {
            string temp;
            temp.push_back(s[idx]);
            temp.push_back(s[idx+1]);
            if(stoi(temp)<=26)
                ans2=recur(idx+2,n,s,dp);
        }
        return dp[idx] = (ans1+ans2);
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+5,-1);
        return recur(0,n,s,dp);
    }
};
