class Solution {
public:
    int recur(int l,int r,vector<int>& nums,vector<vector<int>>& dp) {
        int L=1,R=1;
        if(l-1>=0)
            L=nums[l-1];
        if(r+1<nums.size())
            R=nums[r+1];

        if((r-l+1)==1)
            return dp[l][r] = (L*nums[l]*R);
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            int temp;
            if(i==l || i==r)
            {
                if(i==l)
                    temp=(L*nums[i]*R)+recur(i+1,r,nums,dp);
                else
                    temp=(L*nums[i]*R)+recur(l,i-1,nums,dp);
            }
            else
                temp=(L*nums[i]*R)+recur(l,i-1,nums,dp)+recur(i+1,r,nums,dp);
            ans=max(ans,temp);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(0,n-1,nums,dp);
    }
};
