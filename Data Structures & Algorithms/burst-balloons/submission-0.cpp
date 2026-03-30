class Solution {
public:
    int recur(vector<int>& nums,vector<vector<int>>& dp,int l,int r) {
    if((r-l+1)==1)
        return dp[l][r]=nums[l-1]*nums[l]*nums[r+1];
    if(dp[l][r]!=-1)
        return dp[l][r];
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        int temp=nums[l-1]*nums[i]*nums[r+1];
        temp+=(recur(nums,dp,l,i-1)+recur(nums,dp,i+1,r));
        ans=max(ans,temp);
    }
    return dp[l][r]=ans;
}

int maxCoins(vector<int>& nums) {
    vector<int> V;
    V.push_back(1);
    for(int i=0;i<nums.size();i++)
        V.push_back(nums[i]);
    V.push_back(1);
    int n=V.size();
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(n,-1);
        dp[i]=temp;
    }
    return recur(V,dp,1,n-2);
}
};
