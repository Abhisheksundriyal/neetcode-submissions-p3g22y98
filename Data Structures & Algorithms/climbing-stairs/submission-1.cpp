class Solution {
public:
    int recur(int idx,int n,vector<int>& dp) {
        if(idx>n)
            return 0;
        else if(idx==n)
            return 1;
        else if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx] = (recur(idx+1,n,dp)+recur(idx+2,n,dp));
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        return recur(0,n,dp);
    }
};
