class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int target=-nums[i],l=i+1,r=n-1;
                while(l<r)
                {
                    int sum=nums[l]+nums[r];
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[l],nums[r]});
                        int L=l,R=r;
                        while(l<r && nums[l]==nums[L])
                            l++;
                        while(l<r && nums[r]==nums[R])
                            r--;
                    }
                    else if(sum>target)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};
