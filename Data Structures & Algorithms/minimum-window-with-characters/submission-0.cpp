class Solution {
public:
    bool valid(unordered_map<char,int>& mpS,unordered_map<char,int>& mpT) {
    for(auto itr=mpT.begin();itr!=mpT.end();++itr) {
        pair<int,int> p=(*itr);
        if(p.second>mpS[p.first])
            return false;
    }
    return true;
}

string minWindow(string s, string t) {
    int idx=0,small=INT_MAX,l=2,r=1;
    string ans;
    unordered_map<char,int> mpS,mpT;
    for(int i=0;i<t.length();i++)
        mpT[t[i]]++;
    for(int i=0;i<s.length();i++)
    {
        // cout<<"i: "<<i<<"\n";
        mpS[s[i]]++;
        // cout<<"mpS[s[idx]]: "<<mpS[s[idx]]<<" mpT[s[idx]]: "<<mpT[s[idx]]<<"\n";
        while(idx<=i && mpS[s[idx]]>mpT[s[idx]])
        {
            // cout<<"ch: "<<s[idx]<<"\n";
            // cout<<"mpS[s[idx]]: "<<mpS[s[idx]]<<" mpT[s[idx]]: "<<mpT[s[idx]]<<"\n";
            mpS[s[idx]]--;
            idx++;
        }
        if(valid(mpS,mpT))
        {
            // cout<<"hello world\n";
            if((i-idx+1)<small)
            {
                small=(i-idx+1);
                l=idx;
                r=i;
            }
        }
    }
    for(int i=l;i<=r;i++)
        ans.push_back(s[i]);
    return ans;
}
};
