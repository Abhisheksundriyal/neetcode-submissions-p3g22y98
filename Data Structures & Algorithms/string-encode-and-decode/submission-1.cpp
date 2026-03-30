class Solution {
public:

string encode(vector<string>& strs) {
    string ans;
    int n=strs.size();
    ans=to_string(n);
    ans.push_back('x');
    for(int i=0;i<strs.size();i++)
    {
        ans=ans+to_string(strs[i].size());
        ans.push_back('x');
    }
    for(int i=0;i<strs.size();i++)
        ans=ans+strs[i];
    return ans;
}

vector<string> decode(string s) {
    string x;
    int idx=0;
    for(idx=0;idx<s.length();idx++)
    {
        if(s[idx]=='x')
            break;
        x.push_back(s[idx]);
    }
    vector<int> S;
    S.push_back(stoi(x));
    vector<string> ans;
    for(idx=idx+1;idx<s.length();idx++)
    {
        if(S.size()==S[0]+1)
            break;
        string temp;
        for(;idx<s.length();idx++)
        {
            if(s[idx]=='x')
                break;
            else
                temp.push_back(s[idx]);
        }
        S.push_back(stoi(temp));
    }
    
    for(int i=1;i<S.size();i++)
    {
        string temp;
        for(int j=idx;j<idx+S[i];j++)
            temp.push_back(s[j]);
        idx+=S[i];
        ans.push_back(temp);
    }
    return ans;

}

};
