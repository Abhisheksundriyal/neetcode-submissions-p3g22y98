class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        const n=s.length;
        let ans=0,l=0;
        const st=new Set();
        for(let i=0;i<n;i++) {
            while(st.has(s.charAt(i))) {
                st.delete(s.charAt(l));
                l++;
            }
            st.add(s.charAt(i));
            if(st.size>ans) ans=st.size;
        }
        return ans;
    }
}
