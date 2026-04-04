class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size(),cnt=n/3;
        vector<int> ans;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto itr=mp.begin();itr!=mp.end();++itr) {
            if((*itr).second>cnt) ans.push_back((*itr).first);
        }
        return ans;
    }
};