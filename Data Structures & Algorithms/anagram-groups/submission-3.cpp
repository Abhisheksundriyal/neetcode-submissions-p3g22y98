class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
    vector<vector<string>> ans;
    for(int i=0;i<strs.size();i++)
    {
        vector<int> temp(26,0);
        string key;
        for(int j=0;j<strs[i].size();j++)
            temp[strs[i][j]-'a']++;
        for(int i=0;i<26;i++)
            key+=","+to_string(temp[i]);
        mp[key].push_back(strs[i]);
    }
    for(auto itr=mp.begin();itr!=mp.end();++itr)
    {
        vector<string> temp=(*itr).second;
        ans.push_back((*itr).second);
    }
    return ans;
    }
};
