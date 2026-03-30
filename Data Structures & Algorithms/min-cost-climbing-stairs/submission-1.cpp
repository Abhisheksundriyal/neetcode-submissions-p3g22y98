class Solution {
public:
    void recur(vector<int>& cost,vector<int>& dp,int idx,int n) {
    if(idx>=n)
    {
        dp[idx]=0;
        return;
    }
    if(dp[idx+1]==-1)
        recur(cost,dp,idx+1,n);
    if(dp[idx+2]==-1)
        recur(cost,dp,idx+2,n);
    dp[idx]=cost[idx]+min(dp[idx+1],dp[idx+2]);
}

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+2,-1);
    recur(cost,dp,0,n);
    recur(cost,dp,1,n);
    return min(dp[0],dp[1]);
}

};
