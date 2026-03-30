class Solution {
public:
    int recur(int idx,int n,int sum,vector<int>& nums,vector<unordered_map<int,int>>& dp) {
        if(idx>=n)
        {
            if(sum==0)
                return 1;
            else
                return 0;
        }
        if(dp[idx].find(sum)!=dp[idx].end())
            return dp[idx][sum];
        
        int sum1=sum+nums[idx],sum2=sum-nums[idx],
            ans=recur(idx+1,n,sum1,nums,dp)+recur(idx+1,n,sum2,nums,dp);
        
        return dp[idx][sum] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n+5);
        recur(0,n,target,nums,dp);
        return dp[0][target];
    }
};
