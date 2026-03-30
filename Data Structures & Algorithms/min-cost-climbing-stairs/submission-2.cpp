class Solution {
public:
    int recur(int idx,int n,vector<int>& cost,vector<int>& dp) {
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        return dp[idx] = cost[idx]+min(recur(idx+1,n,cost,dp),recur(idx+2,n,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+5,-1);
        return min(recur(0,n,cost,dp),recur(1,n,cost,dp));
    }
};
