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
                cout<<"nums[i]: "<<nums[i]<<"\n";
                for(int j=i+1;j<n-1;j++)
                {
                    if(j==i+1 || nums[j]!=nums[j-1])
                    {
                        int have=nums[i]+nums[j],need=-have,l=j+1,r=n-1;
                        while(l<=r)
                        {
                            int mid=(l+r)/2;
                            if(nums[mid]==need)
                            {
                                ans.push_back({nums[i],nums[j],nums[mid]});
                                break;
                            }
                            else if(nums[mid]>need)
                                r=mid-1;
                            else
                                l=mid+1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
