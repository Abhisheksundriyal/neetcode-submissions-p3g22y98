class Solution {
public:
    int recur(vector<int>& cost,vector<int>& dp,int idx,int n) {
    if(idx>=n)
        return 0;
    if(dp[idx+1]==-1)
        dp[idx+1]=recur(cost,dp,idx+1,n);
    if(dp[idx+2]==-1)
        dp[idx+2]=recur(cost,dp,idx+2,n);
    return dp[idx]=cost[idx]+min(dp[idx+1],dp[idx+2]);
}

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+1,-1);
    return min(recur(cost,dp,0,n),recur(cost,dp,1,n));
}
};
