class Solution {
public:
    unordered_map<char,vector<char>> mp;
vector<string> recur(string digits,int idx) {
    vector<string> curr,next,ans;
    if(digits=="")
        return curr;
    for(int i=0;i<mp[digits[idx]].size();i++) {
        string temp="";
        temp+=mp[digits[idx]][i];
        curr.push_back(temp);
    }

    if(idx==digits.size()-1)
        return curr;
    next=recur(digits,idx+1);
    for(int i=0;i<curr.size();i++)
    {
        for(int j=0;j<next.size();j++)
            ans.push_back(curr[i]+next[j]);
    }
    return ans;
}
vector<string> letterCombinations(string digits) {
    char num='2';
    string curr;
    for(char ch='a';ch<='z';ch++) {
        mp[num].push_back(ch);
        if(ch=='c' || ch=='f' || ch=='i' || ch=='l' ||ch=='o' ||
            ch=='s' || ch=='v' || ch=='z')
            num++;
    }
    for(auto itr=mp.begin();itr!=mp.end();++itr)
    {
        cout<<(*itr).first<<" : ";
        for(int i=0;i<(*itr).second.size();i++)
            cout<<(*itr).second[i]<<" ";
        cout<<"\n";
    }
    return recur(digits,0);
}
};
