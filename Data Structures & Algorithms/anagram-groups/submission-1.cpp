class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> myMap;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++) {
            string& s=strs[i];
            string key;
            vector<int> cnt(26,0);
            for(int j=0;j<s.length();j++)
                cnt[s[j]-'a']++;
            for(int j=0;j<26;j++)
                key+=','+to_string(cnt[j]);
            myMap[key].push_back(s);
        }
        for(auto itr=myMap.begin();itr!=myMap.end();++itr)
            ans.push_back((*itr).second);
        return ans;
    }
};
