class Solution {
    isAlphaNumeric(ch) {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
        return false;
        
    }
    isPalindrome(s) {
        let l=0,r=s.length-1;
        while(l<r) {
            while(l<=r && !this.isAlphaNumeric(s.charAt(l))) l++;
            while(l<=r && !this.isAlphaNumeric(s.charAt(r))) r--;
            if(l<=r && s.charAt(l).toLowerCase()!=s.charAt(r).toLowerCase()) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
