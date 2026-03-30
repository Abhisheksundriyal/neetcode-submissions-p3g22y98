class Solution {
public:
    int recur(vector<int>& prices,vector<vector<int>>& dp,int idx,int buying,int n) {
    if(idx>=n)
        return dp[idx][buying] = 0;
    if(dp[idx][buying]!=-1)
        return dp[idx][buying];

    if(buying)
    {
        int buy=recur(prices,dp,idx+1,0,n)-prices[idx],cooldown=recur(prices,dp,idx+1,1,n);
        dp[idx][buying] = max(buy, cooldown);
    }
    else
    {
        int sell=recur(prices,dp,idx+2,1,n)+prices[idx],cooldown=recur(prices,dp,idx+1,0,n);
        dp[idx][buying] = max(sell,cooldown);
    }
    return dp[idx][buying];
}



int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+3);
    for(int i=0;i<n+3;i++)
    {
        vector<int> temp(2,-1);
        dp[i]=temp;
    }
    return recur(prices,dp,0,1,n);
}
};
