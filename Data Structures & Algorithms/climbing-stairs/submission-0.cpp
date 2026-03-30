class Solution {
public:
    int recur(vector<int>& dp,int idx,int n) {
    if(idx>=n)
        return 1;
    if(dp[idx+1]==-1)
        dp[idx+1]=recur(dp,idx+1,n);
    if(dp[idx+2]==-1)
        dp[idx+2]=recur(dp,idx+2,n);
    return dp[idx]=dp[idx+1]+dp[idx+2];
}

int climbStairs(int n) {
    vector<int> dp(n+2,-1);
    return recur(dp,1,n);
}
};
