class Solution {
public:
    bool isPalindromw(string s) {
    int l=0,r=s.length()-1;
    if(l<=r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    return false;
}

bool isValid(vector<string>& temp,string& s) {
    int n=temp.size();
    string x;
    for(int i=0;i<n;i++)
    {
        x+=temp[i];
        if(!isPalindromw(temp[i]))
            return false;
    }
    if(x!=s)
        return false;
    return true;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    int n=s.length(),r=(1 << n);
    for(int i=1;i<r;i++)
    {
        vector<string> temp;
        string x;
        for(int j=0;j<n;j++)
        {
            int num=(1 << j);
            x.push_back(s[j]);
            if((num & i)!=0)
            {
                temp.push_back(x);
                x="";
            }
        }
        if(isValid(temp,s))
            ans.push_back(temp);
    }
    return ans;

}
};
