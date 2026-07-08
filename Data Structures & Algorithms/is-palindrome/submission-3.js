class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isAlphaNumeric(ch) {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
        return false;
        
    }
    isPalindrome(s) {
        
        let l=0,r=s.length-1;
        // console.log(l+" "+r+"\n");
        while(l<r) {
            while(l<=r && !this.isAlphaNumeric(s.charAt(l))) l++;
            while(l<=r && !this.isAlphaNumeric(s.charAt(r))) r--;
            // console.log(l+" "+r+"\n");
            // console.log("s[l]: "+s.charAt(l).toLowerCase()+"\n");
            // console.log("s[r]: "+s.charAt(r).toLowerCase()+"\n");
            if(l<=r && s.charAt(l).toLowerCase()!=s.charAt(r).toLowerCase()) {
                // console.log("false at: ");
                // console.log(l+" "+r+"\n");
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
