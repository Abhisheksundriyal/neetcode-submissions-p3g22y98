class Solution {
public:
    int recur(int amount,vector<int>& coins,int n,vector<int>& dp) {
        if(amount==0)
            return dp[amount] = 0;
        if(dp[amount]!=-1)
            return dp[amount];
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(amount-coins[i]<0)
                break;
            int temp=recur(amount-coins[i],coins,n,dp);
            if(temp!=INT_MAX)
                ans=min(ans,1+temp);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+5,-1);
        recur(amount,coins,n,dp);
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};
