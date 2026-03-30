class Solution {
public:
    int recur(int idx,int n,vector<int>& nums,vector<int>& dp) {
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=nums[idx]+max(recur(idx+2,n,nums,dp),recur(idx+3,n,nums,dp));
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+5,-1);
        return max(recur(0,n,nums,dp),recur(1,n,nums,dp));
    }
};
