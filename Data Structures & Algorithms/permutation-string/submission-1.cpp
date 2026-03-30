class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        int n=s1.size(),m=s2.size(),count=0,idx=0;
        vector<int> cnt1(26,0),cnt2(26,0);
        for(int i=0;i<n;i++)
            cnt1[s1[i]-'a']++;
        for(int i=0;i<m;i++)
        {
            cnt2[s2[i]-'a']++;
            count++;
            if(count>n)
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
