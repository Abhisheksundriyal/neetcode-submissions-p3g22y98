class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size(),l=0,r=nums.size(),idx=-1;
        if(nums[0]<=nums[n-1])
            return nums[0];
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<=nums[0] && nums[mid]<=nums[n-1])
            {
                idx=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return nums[idx];
    }
};
