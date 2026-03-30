class Solution {
public:
    void recur(vector<int>& nums,vector<int>& dp,int idx,int n) {
    if(idx>=n)
    {
        dp[idx]=0;
        return;
    }
    if(dp[idx+2]==-1)
        recur(nums,dp,idx+2,n);
    if(dp[idx+3]==-1)
        recur(nums,dp,idx+3,n);
    dp[idx]=nums[idx]+max(dp[idx+2],dp[idx+3]);
}

int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n+10,-1);
    recur(nums,dp,0,n);
    recur(nums,dp,1,n);
    return max(dp[0],dp[1]);
}
};
