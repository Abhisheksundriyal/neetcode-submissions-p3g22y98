class Solution {
public:
    int recur(int i,int j,int n,vector<int>& prices,vector<vector<int>>& dp) {
        if(i>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(j==1)
        {
            int temp1=recur(i+1,0,n,prices,dp)-prices[i],temp2=recur(i+1,1,n,prices,dp);
            return dp[i][j] = max(temp1,temp2);
        }
        int temp1=recur(i+2,1,n,prices,dp)+prices[i],temp2=recur(i+1,0,n,prices,dp);
        return dp[i][j] = max(temp1,temp2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        recur(0,1,n,prices,dp);
        // return max((int)0,dp[0][1]);
        return dp[0][1];
    }
};