class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> cnt;
        int idx=0,count=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]]++;
            count++;
            while(cnt[s[i]]>1)
            {
                cnt[s[idx]]--;
                idx++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
