class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
        return false;
    int n=s1.length(),m=s2.length(),idx=0;
    vector<int> cnt1(26,0),cnt2(26,0);
    for(int i=0;i<n;i++)
        cnt1[s1[i]-'a']++;
    for(int i=0;i<m;i++)
    {
        cnt2[s2[i]-'a']++;
        if((i-idx+1)>n)
        {
            cnt2[s2[idx]-'a']--;
            idx++;
        }
        if(cnt1==cnt2)
            return true;
    }
    return false;
    }
};
