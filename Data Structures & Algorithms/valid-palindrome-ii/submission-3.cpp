class Solution {
public:
    bool check(string& s,int l,int r,int count) {
        if(l==r) return true;
        if(l+1==r) {
            if(s[l]==s[r]) return true;
            return (count>0);
        }
        if(s[l]==s[r]) return check(s,l+1,r-1,count);

        if(count==0) return false;

        return (check(s,l+1,r,0) || check(s,l,r-1,0));
    }
    bool validPalindrome(string s) {
        
        int l=0,r=s.size()-1;

        return check(s,l,r,1);



    }
};