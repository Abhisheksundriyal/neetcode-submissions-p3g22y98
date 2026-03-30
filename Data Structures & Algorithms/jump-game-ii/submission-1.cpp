class Solution {
public:
    int recur(int idx,int n,vector<int>& nums,vector<int>& dp) {
        if(idx>=n)
            return INT_MAX;
        if(idx==n-1)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++)
        {
            int temp=recur(idx+i,n,nums,dp);
            if(temp!=INT_MAX)
                ans=min(ans,1+temp);
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(0,n,nums,dp);
    }
};
