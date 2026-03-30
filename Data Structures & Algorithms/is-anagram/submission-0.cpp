class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cntS(26,0),cntT(26,0);
        for(int i=0;i<s.length();i++)
            cntS[s[i]-'a']++;
        for(int i=0;i<t.length();i++)
            cntT[t[i]-'a']++;
        for(int i=0;i<26;i++) {
            if(cntS[i]!=cntT[i])
                return false;
        }
        return true;
    }
};
