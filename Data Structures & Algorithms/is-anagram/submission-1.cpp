class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnts(26,0),cntt(26,0);
        for(int i=0;i<s.size();i++)
            cnts[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            cntt[t[i]-'a']++;
        return (cnts==cntt);
    }
};
