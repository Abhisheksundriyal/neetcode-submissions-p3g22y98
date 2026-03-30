class Solution {
public:

    string encode(vector<string>& strs) {
    string ans;
    ans+=to_string(strs.size());
    ans.push_back(',');
    for(int i=0;i<strs.size();i++)
    {
        ans+=to_string(strs[i].size());
        ans.push_back(',');
    }
    for(int i=0;i<strs.size();i++)
        ans+=strs[i];
    return ans;
}

vector<string> decode(string s) {
    vector<string> ans;
    vector<int> V;
    string temp;
    for(int idx=0;idx<s.length();idx++) {
        if(s[idx]!=',')
            temp.push_back(s[idx]);
        else
        {
            V.push_back(stoi(temp));
            temp="";
            if(V.size()==V[0]+1)
            {
                idx++;
                for(int i=1;i<V.size();i++)
                {
                    int start=idx;
                    for(;idx<start+V[i];idx++)
                        temp.push_back(s[idx]);
                    ans.push_back(temp);
                    temp="";
                }
                break;
            }
        }
    }
    return ans;
}
};
