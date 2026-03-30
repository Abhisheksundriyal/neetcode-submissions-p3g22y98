class Solution {
public:
    int recur(int i,int j,int n,int m,string& word1,string& word2,vector<vector<int>>& dp) {
        if(i>=n && j>=m)
            return 0;
        if(i>=n || j>=m)
        {
            if(i>=n)
                return (m-j);
            return (n-i);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j])
        {
            int ans1=recur(i+1,j+1,n,m,word1,word2,dp);
            ans=min(ans,ans1);
        }
        int ans2=1+recur(i,j+1,n,m,word1,word2,dp),
            ans3=1+recur(i+1,j,n,m,word1,word2,dp),
            ans4=1+recur(i+1,j+1,n,m,word1,word2,dp);
        ans=min(ans,min(ans2,min(ans3,ans4)));
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(0,0,n,m,word1,word2,dp);
    }
};
