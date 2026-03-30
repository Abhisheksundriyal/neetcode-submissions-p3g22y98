class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,idx=0,count=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            count++;
            while(mp[s[i]]>1)
            {
                mp[s[idx]]--;
                count--;
                idx++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
