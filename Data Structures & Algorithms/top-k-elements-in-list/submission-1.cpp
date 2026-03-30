class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int> mp;
    unordered_map<int,unordered_set<int>> mp2;
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
    for(int i=0;i<n;i++)
    {
        int occ=mp[nums[i]];
        mp2[occ].insert(nums[i]);
    }
    for(int i=n;i>=1;i--)
    {
        for(auto itr=mp2[i].begin();itr!=mp2[i].end();++itr)
        {
            int temp=(*itr);
            if(k>0)
            {
                ans.push_back(temp);
                k--;
            }
            else
                break;
        }
    }
    return ans;
}
};
