class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l=0,r=nums.size()-1,idx=-1,n=nums.size();
        if(nums[0]<nums[n-1])
            return 0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>=nums[0] && nums[mid]>nums[n-1])
                l=mid+1;
            else
            {
                idx=mid;
                r=mid-1;
            }
        }
        return idx;
    }
    int binarySearch(vector<int>& nums,int l,int r,int target) {
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>target)
                r=mid-1;
            else if(nums[mid]<target)
                l=mid+1;
            else
                return mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int idx=findPivot(nums),n=nums.size(),ans=binarySearch(nums,0,idx-1,target);
        if(ans==-1)
            ans=binarySearch(nums,idx,n-1,target);
        return ans;
    }
};
