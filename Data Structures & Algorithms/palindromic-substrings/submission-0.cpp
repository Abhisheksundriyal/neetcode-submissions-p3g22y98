class Solution {
public:

    int solve(string& s,int l,int r) {
        int count=0;
        while(l>=0 && r<s.length() && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n=s.length(),count=0;
        for(int i=0;i<n;i++)
        {
            count+=solve(s,i,i);
            if(i+1<n)
                count+=solve(s,i,i+1);
        }
        return count;
    }
};
