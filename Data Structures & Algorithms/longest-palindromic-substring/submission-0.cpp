class Solution {
public:
    string solve(string s,int l,int r) {
    string ans;
    if(s[l]!=s[r])
        return "";
    while(l>=0 && r<s.length() && s[l]==s[r])
    {
        l--;
        r++;
    }
    l++;
    r--;
    for(int i=l;i<=r;i++)
        ans.push_back(s[i]);
    return ans;
}

string longestPalindrome(string s) {
    int n=s.length();
    string ans;
    for(int i=0;i<n;i++)
    {
        int l=i,r=i;
        string temp=solve(s,l,r);
        // cout<<"temp: "<<temp<<"\n";
        if(temp.length()>ans.length())
            ans=temp;
        if(i+1<n)
        {
            r=i+1;
            temp=solve(s,l,r);
            // cout<<"temp: "<<temp<<"\n";
            if(temp.length()>ans.length())
                ans=temp;
        }
    }
    return ans;
}
};
