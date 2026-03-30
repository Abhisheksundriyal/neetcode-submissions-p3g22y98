class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),r=(1 << n);
        vector<vector<int>> ans;
        for(int i=0;i<r;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                int num=(1 << j);
                if((i & num)!=0)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
