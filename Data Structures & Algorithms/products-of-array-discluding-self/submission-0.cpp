class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n),right(n),ans(n);
        for(int i=0;i<n;i++)
        {
            left[i]=nums[i];
            if(i>0)
                left[i]*=left[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i]=nums[i];
            if(i<n-1)
                right[i]*=right[i+1];
        }
        for(int i=0;i<n;i++)
        {
            int l=1,r=1;
            if(i>0)
                l=left[i-1];
            if(i<n-1)
                r=right[i+1];
            ans[i]=(l*r);
        }
        return ans;
    }
};
