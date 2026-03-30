class Solution {
public:
    bool recur(vector<int>& nums,vector<vector<int>>& dp,int n,int idx,int amount) {
    if(amount==0)
    {
        dp[idx][amount]=1;
        return true;
    }
    if(idx>=n)
    {

        dp[idx][amount]=-1;
        return false;
    }
    bool ans=false;

    if((amount-nums[idx])>=0)
    {
        if(dp[idx+1][amount-nums[idx]]==0)
            recur(nums,dp,n,idx+1,amount-nums[idx]);

        if(dp[idx+1][amount-nums[idx]]==1)
            ans=true;
    }
    

    if(dp[idx+1][amount]==0)
        recur(nums,dp,n,idx+1,amount);
    if(dp[idx+1][amount]==1)
        ans=true;

    if(ans)
        dp[idx][amount]=1;
    else
        dp[idx][amount]=-1;

    return ans;
}

bool canPartition(vector<int>& nums) {
    int sum=0,n=nums.size();
    for(int i=0;i<n;i++)
        sum+=nums[i];
    if(sum%2==1)
        return false;
    sum=sum/2;
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(sum+1,0);
        dp[i]=temp;
    }
    return recur(nums,dp,n,0,sum);
}
};
