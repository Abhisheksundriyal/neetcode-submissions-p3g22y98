class Solution {
public:

    bool alphaNum(char ch) {
        return ((ch>='A' && ch<='Z') ||
                (ch>='a' && ch<='z') ||
                (ch>='0' && ch<='9'));
    }

    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r) {
            while(l<r && !alphaNum(s[l]))
                l++;
            while(l<r && !alphaNum(s[r]))
                r--;
            if(tolower(s[l])!=tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
