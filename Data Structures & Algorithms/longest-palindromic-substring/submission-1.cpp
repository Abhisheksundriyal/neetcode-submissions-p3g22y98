class Solution {
public:
    string findPalindrome(string& s,int n,int l,int r) {
        string ans;
        while(l>=0 && r<n && s[l]==s[r]) {
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
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++) {
            string temp=findPalindrome(s,n,i,i);
            if(temp.size()>ans.size())
                ans=temp;
            if(i<n-1 && s[i]==s[i+1])
            {
                temp=findPalindrome(s,n,i,i+1);
                if(temp.size()>ans.size())
                    ans=temp;
            }
        }
        return ans;
    }
};
