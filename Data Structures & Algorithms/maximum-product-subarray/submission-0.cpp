class Solution {
public:

    int solve(vector<int>& nums,int l,int r) {
        int ans=0,pro=0;
        for(int i=l;i<=r;i++)
        {
            if(pro==0)
                pro=nums[i];
            else
                pro*=nums[i];
            ans=max(ans,pro);
        }
        pro=0;
        for(int i=r;i>=l;i--)
        {
            if(pro==0)
                pro=nums[i];
            else
                pro*=nums[i];
            ans=max(ans,pro);
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int ans=0,n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                int idx=i;
                while(idx<n && nums[idx]!=0)
                    idx++;
                idx--;
                ans=max(ans,solve(nums,i,idx));
                i=idx;
            }
            else
                count++;
        }
        if(count==n)
            return 0;
        return ans;
    }
};
