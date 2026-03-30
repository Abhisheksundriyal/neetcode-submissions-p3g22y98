class Solution {
public:
    bool isPalindrome(string& s) {
    int l=0,r=s.length()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool isValid(vector<string>& temp,string& s) {
    int count=0;
    for(int i=0;i<temp.size();i++)
    {
        count+=temp[i].length();
        if(!isPalindrome(temp[i]))
            return false;
    }
    if(count!=s.length())
        return false;
    return true;
}

vector<vector<string>> partition(string s) {
    int n=s.length();
    vector<vector<string>> ans;
    for(int i=0;i<(1 << n);i++)
    {
        vector<string> temp;
        string str;
        // cout<<"hello world\n";
        for(int j=0;j<n;j++)
        {
            int num=(1 << j);
            str.push_back(s[j]);
            if((num & i)!=0)
            {
                // cout<<"str: "<<str<<"\n";
                temp.push_back(str);
                str="";
            }
        }
        // if(str!="")
        //     temp.push_back(str);
        if(isValid(temp,s))
            ans.push_back(temp);
    }
    return ans;
}
};
