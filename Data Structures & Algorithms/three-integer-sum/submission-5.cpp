class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<nums.size()-2;)
    {
        int target=-nums[i],l=i+1,r=nums.size()-1,I=i;
        cout<<"target: "<<target<<"\n";
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum<target)
                l++;
            else if(sum>target)
                r--;
            else
            {
                ans.push_back({nums[i],nums[l],nums[r]});
                int L=l,R=r;
                while(l<r && nums[l]==nums[L])
                    l++;
                while(l<r && nums[r]==nums[R])
                    r--;
            }
        }
        while(nums[I]==nums[i])
            I++;
        i=I;
    }
    return ans;
    }
};
