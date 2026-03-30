class Solution {
public:
    bool check(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2)
{
    for(auto itr=mp1.begin();itr!=mp1.end();itr++)
    {
        pair<char,int> p=(*itr);
        if(p.second>mp2[p.first])
            return false;
    }
    return true;
}
string minWindow(string s, string t) {
    unordered_map<char,int> mp1,mp2;
    int n=s.size(),m=t.size(),idx=0,small=INT_MAX,l=1,r=0;
    string ans;
    for(int i=0;i<m;i++)
        mp1[t[i]]++;
    for(int i=0;i<n;i++)
    {
        mp2[s[i]]++;
        while(idx<=i && mp2[s[idx]]>mp1[s[idx]])
        {
            mp2[s[idx]]--;
            idx++;
        }
        if(check(mp1,mp2))
        {
            int temp=i-idx+1;
            if(temp<small)
            {
                l=idx;
                r=i;
                small=temp;
            }
        }
    }
    for(int i=l;i<=r;i++)
        ans.push_back(s[i]);
    return ans;
}
};
