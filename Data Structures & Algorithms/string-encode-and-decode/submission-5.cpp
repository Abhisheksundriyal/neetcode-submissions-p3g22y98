class Solution {
public:

    string encode(vector<string>& strs) {
    string ans;
    ans+=to_string(strs.size())+",";
    for(int i=0;i<strs.size();i++)
        ans+=to_string(strs[i].size())+",";
    for(int i=0;i<strs.size();i++)
        ans+=strs[i];
    return ans;
}

vector<string> decode(string s) {
    string temp;
    int idx=0;
    vector<int> SZ;
    vector<string> ans;
    for(;idx<s.size();idx++)
    {
        if(SZ.size()!=0 && SZ.size()==SZ[0]+1)
            break;
        if(s[idx]!=',')
            temp.push_back(s[idx]);
        else
        {
            SZ.push_back(stoi(temp));
            temp="";
        }
    }
    temp="";
    for(int i=1;i<SZ.size();i++)
    {
        int r=idx+SZ[i];
        for(;idx<r;idx++)
            temp.push_back(s[idx]);
        ans.push_back(temp);
        temp="";
    }
    return ans;
}
};
