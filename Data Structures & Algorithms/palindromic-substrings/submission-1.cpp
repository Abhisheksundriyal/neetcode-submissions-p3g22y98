class Solution {
public:
    int solve(string& s,int n,int l,int r) {
        int count=0;
        while(l>=0 && r<n && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=solve(s,n,i,i);
            if(i+1<n)
                ans+=solve(s,n,i,i+1);
        }
        return ans;
    }
};
