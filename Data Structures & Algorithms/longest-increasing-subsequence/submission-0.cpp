class Solution {
public:
    int binarySearch(vector<int>& temp,int l,int r,int target) {
    int idx=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(temp[mid]>=target)
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
    vector<int> temp;
    int n=0;
    for(int i=0;i<nums.size();i++)
    {
        if(n==0 || temp[n-1]<nums[i])
        {
            temp.push_back(nums[i]);
            n++;
        }
        int idx=binarySearch(temp,0,n-1,nums[i]);
        if(idx!=-1)
            temp[idx]=nums[i];
    }
    return temp.size();
}
};
