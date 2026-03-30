class Solution {
public:
    bool isPalindrome(string& s){
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool check(vector<string>& V,string s) {
        string temp;
        for(int i=0;i<V.size();i++)
        {
            temp+=V[i];
            if(!isPalindrome(V[i]))
                return false;
        }
        if(temp!=s)
            return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        for(int i=1;i<(1 << n);i++) {
            vector<string> temp;
            string t;
            for(int j=0;j<n;j++)
            {
                t.push_back(s[j]);
                int num=(1 << j);
                if((num & i)!=0)
                {
                    temp.push_back(t);
                    t="";
                }
            }
            if(check(temp,s))
                ans.push_back(temp);
        }
        return ans;
    }
};
