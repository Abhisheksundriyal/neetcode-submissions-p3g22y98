class Solution {
public:
    int recur(int idx,int n,int sum,vector<int>& nums,vector<vector<int>>& dp) {
        if(sum==0)
            return dp[idx][sum] = 1;
        if(idx>=n || sum<0)
            return 0;
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        if(recur(idx+1,n,sum-nums[idx],nums,dp) || recur(idx+1,n,sum,nums,dp))
            return dp[idx][sum] = 1;
        return dp[idx][sum] = 0;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum/=2;
        vector<vector<int>> dp(n+5,vector<int>(sum+5,-1));
        sort(nums.begin(),nums.end());
        recur(0,n,sum,nums,dp);
        return (dp[0][sum] == 1);
    }
};
