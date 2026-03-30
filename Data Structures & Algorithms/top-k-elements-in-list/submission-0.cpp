class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    int n=nums.size(),count=0;
    unordered_map<int,int> mymap1;
    vector<vector<int>> cnt(n+1);
    vector<int> ans;
    for(int i=0;i<n;i++)
        mymap1[nums[i]]++;
    for(auto itr=mymap1.begin();itr!=mymap1.end();++itr)
    {
        pair<int,int> p=(*itr);
        cnt[p.second].push_back(p.first);
    }
    for(int i=n;i>0 && count<k;i--)
    {
        vector<int>& temp=cnt[i];
        for(int j=0;j<temp.size() && count<k;j++)
        {
            ans.push_back(temp[j]);
            count++;
        }
    }
    return ans; 
    }
};
