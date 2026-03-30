class Solution {
public:

    int findPivot(vector<int>& nums) {
        int n=nums.size(),idx,l=0,r=n-1;
        if(nums[0]<=nums[n-1])
            return 0;
        while(l<=r) {
            int mid=(l+r)/2;
            if(nums[mid]<=nums[0] && nums[mid]<=nums[n-1])
            {
                idx=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return idx;
    }

    int binarySearch(vector<int>& nums,int l,int r,int target) {
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size(),idx=findPivot(nums),ans=binarySearch(nums,0,idx-1,target);
        if(ans==-1)
        {
            ans=binarySearch(nums,idx,n-1,target);
            if(ans!=-1)
                return ans;
        }
        else
            return ans;
        return -1;
    }
};
