class Solution {
    /**
     * @param {string} s1
     * @param {string} s2
     * @return {boolean}
     */
    check(mp1,mp2) {
        for(let i=0;i<26;i++) {
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
    checkInclusion(s1, s2) {
        const mp1=[],mp2=[];
        for(let i=0;i<26;i++) {
            mp1.push(0);
            mp2.push(0);
        }
        const n=s1.length,m=s2.length;
        let l=0;

        for(let i=0;i<n;i++) {
            let idx = s1.charCodeAt(i)-'a'.charCodeAt(0);
            mp1[idx]++;
        }
        for(let i=0;i<m;i++) {
            let idx = s2.charCodeAt(i)-'a'.charCodeAt(0);
            mp2[idx]++;
            let idx2=s2.charCodeAt(l)-'a'.charCodeAt(0);
            while(mp2[idx2]-1>=mp1[idx2]) {
                l++;
                mp2[idx2]--;
                idx2=s2.charCodeAt(l)-'a'.charCodeAt(0);
            }
            if(this.check(mp1,mp2)) return true;
        }
        return false;
    }
}
