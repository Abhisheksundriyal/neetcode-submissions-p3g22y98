class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isOp(ch) {
        return (ch=='(' || ch=='{' || ch=='[');
    }
    sameType(ch1,ch2) {
        if((ch1=='(' || ch1==')') && (ch2=='(' || ch2==')')) return true;
        if((ch1=='{' || ch1=='}') && (ch2=='{' || ch2=='}')) return true;
        if((ch1=='[' || ch1==']') && (ch2=='[' || ch2==']')) return true;
        return false;
    }
    isValid(s) {
        let n=s.length,l=0;
        const arr=[];
        arr.length=n;
        for(let i=0;i<n;i++) {
            if(l==0 || this.isOp(s.charAt(i)) || !this.isOp(arr[l-1])
                || !this.sameType(arr[l-1],s.charAt(i))) {
                arr[l]=s.charAt(i);
                l++;
            } else {
                l--;
            }
        }

        return (l==0);

    }
}
