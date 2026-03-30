class Solution {
public:
    unordered_map<char,vector<char>> mp;
vector<string> recur(string& digits,int idx,int n) {
    if(idx==n)
        return {};
    vector<string> curr,next,ans;
    char ch=digits[idx];
    for(int i=0;i<mp[digits[idx]].size();i++)
    {
        string temp;
        temp.push_back(mp[digits[idx]][i]);
        curr.push_back(temp);
    }
    next=recur(digits,idx+1,n);
    if(next.size()==0)
        return curr;
    for(int i=0;i<curr.size();i++)
    {
        for(int j=0;j<next.size();j++)
            ans.push_back(curr[i]+next[j]);
    }
    return ans;
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    char num='2';
    int n=digits.size();
    for(char ch='a';ch<='z';ch++)
    {
        mp[num].push_back(ch);
        if(ch=='c' || ch=='f' || ch=='i' || ch=='l' ||
             ch=='o' || ch=='s' || ch=='v' || ch=='z')
            num++;
    }
    return recur(digits,0,n);
}
};
