class Solution {
public:
    int findMin(vector<int> &nums) {
    int l=0,r=nums.size()-1,ans,n=nums.size();
    // cout<<"l: "<<l<<" r: "<<r<<"\n";
    if(nums[0]<nums[n-1] || n==1)
        return nums[0];
    while(l<=r)
    {
        int mid=(l+r)/2;
        // cout<<"mid: "<<mid<<"\n";
        if(nums[mid]>=nums[0] && nums[mid]>nums[n-1])
            l=mid+1;
        else if(nums[mid]<nums[0] && nums[mid]<=nums[n-1])
        {
            ans=nums[mid];
            r=mid-1;
        }
        // cout<<"l: "<<l<<" r: "<<r<<"\n";
    }
    return ans;
}
};
