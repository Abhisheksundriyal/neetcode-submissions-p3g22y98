class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            for(int j=0;j<mp[need].size();j++)
            {
                if(mp[need][j]!=i)
                    return {i,mp[need][j]};
            }
        }
        return {};
    }
};
