class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n=nums.size(),ans=0;
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];

        for(int i=0;i<n;i++) {
            int need=nums[i]-k;
            ans+=mp[need];
            mp[nums[i]]++;
        }

        return ans;

    }
};