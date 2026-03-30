class Solution {
public:
    int solve(vector<int>& nums,int l,int r) {
        int pro=1,count=0,num=INT_MAX,left=1,right=1;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]<0)
                count++;
            pro*=nums[i];
        }
        for(int i=l;i<=r;i++)
        {
            left*=nums[i];
            pro=max(pro,left);
        }
        for(int i=r;i>=l;i--)
        {
            right*=nums[i];
            pro=max(pro,right);
        }
        return pro;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),ans=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                int idx=i;
                while(idx<n && nums[idx]!=0)
                    idx++;
                ans=max(ans,solve(nums,i,idx-1));
                i=idx-1;
            }
            else
                ans=max(ans,nums[i]);
        }
        return ans;
    }
};
