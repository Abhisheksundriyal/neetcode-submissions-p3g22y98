class Solution {
public:
    int recur(int idx,int n,string& s,vector<string>& wordDict,vector<int>& dp) {
        if(idx>=n)
            return dp[idx] = 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        for(int i=0;i<wordDict.size();i++)
        {
            if((n-idx)>=wordDict[i].size())
            {
                string temp;
                int j=idx;
                for(int k=0;k<wordDict[i].size();k++)
                {
                    if(wordDict[i][k]!=s[j])
                        break;
                    temp.push_back(s[j]);
                    j++;
                }
                if(temp==wordDict[i] && recur(idx+temp.size(),n,s,wordDict,dp))
                {
                    ans=1;
                    break;
                }
            }
        }
        return dp[idx] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+5,-1);
        recur(0,n,s,wordDict,dp);
        return (dp[0] == 1);
    }
};
