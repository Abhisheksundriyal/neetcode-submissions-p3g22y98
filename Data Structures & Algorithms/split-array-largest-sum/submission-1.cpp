class Solution {
public:
    bool check(int sum,vector<int>& nums,int k) {
        int count=1,curr=0;
        for(int i=0;i<(int)nums.size();i++) {
            if(nums[i]>sum) return false;
            if(curr+nums[i]>sum) {
                count++;
                curr=nums[i];
            } else curr+=nums[i];
        }
        return (count<=k);
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++) r+=nums[i];
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(mid,nums,k)) {
                ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        return ans;
    }
};