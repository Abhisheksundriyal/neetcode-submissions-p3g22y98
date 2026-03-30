class Solution {
public:
    int recur(int idx,int n,vector<int>& nums,vector<int>& dp) {
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans1=recur(idx+1,n,nums,dp),
            ans2=nums[idx]+recur(idx+2,n,nums,dp),
            ans3=nums[idx]+recur(idx+3,n,nums,dp);
        return dp[idx] = max(ans1,max(ans2,ans3));
    }
    int robI(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+5,-1);
        return recur(0,n,nums,dp);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1,nums2;
        for(int i=0;i<n;i++) {
            if(i==0)
                nums1.push_back(nums[i]);
            else if(i==n-1)
                nums2.push_back(nums[i]);
            else
            {
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        return max(robI(nums1),robI(nums2));
    }
};
