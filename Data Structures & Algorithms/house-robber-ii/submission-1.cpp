class Solution {
public:
    void recur(vector<int>& V,vector<int>& dp,int idx,int n) {
    if(idx>=n)
    {
        dp[idx]=0;
        return;
    }
    if(dp[idx+2]==-1)
        recur(V,dp,idx+2,n);
    if(dp[idx+3]==-1)
        recur(V,dp,idx+3,n);
    dp[idx]=V[idx]+max(dp[idx+2],dp[idx+3]);
}

int houseRobberI(vector<int>& nums,int l,int r) {
    int n=(r-l+1);
    vector<int> V;
    for(int i=l;i<=r;i++)
        V.push_back(nums[i]);
    vector<int> dp(n+10,-1);
    recur(V,dp,0,n);
    recur(V,dp,1,n);
    return max(dp[0],dp[1]);
}

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return nums[0];
    return max(houseRobberI(nums,0,n-2),houseRobberI(nums,1,n-1));
}
};
