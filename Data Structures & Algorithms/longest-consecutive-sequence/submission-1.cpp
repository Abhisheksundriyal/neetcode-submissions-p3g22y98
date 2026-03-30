class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]+=mp[nums[i]-1]+mp[nums[i]+1]+1;
                mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
                mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
            }
            ans=max(ans,mp[nums[i]]);
        }
        return ans;
    }
};
