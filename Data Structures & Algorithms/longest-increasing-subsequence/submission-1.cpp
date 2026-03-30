class Solution {
public:
    int binarySearch(vector<int>& dp,int l,int r,int target) {
        int idx=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(dp[mid]>=target)
            {
                idx=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return idx;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();i++) {
            if(dp.size()==0 || nums[i]>dp[dp.size()-1])
                dp.push_back(nums[i]);
            else
            {
                int idx=binarySearch(dp,0,dp.size()-1,nums[i]);
                dp[idx]=nums[i];
            }
        }
        return dp.size();
    }
};
