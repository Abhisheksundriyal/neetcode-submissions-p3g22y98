class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        const mp = new Map();
        for(let i=0;i<s.length;i++) {
            if(!mp.has(s.charAt(i)))
                mp.set(s.charAt(i),1);
            else {
                mp.set(s.charAt(i),mp.get(s.charAt(i))+1);
            }
        }
        for(let i=0;i<t.length;i++) {
            if(!mp.has(t.charAt(i)))
                mp.set(t.charAt(i),-1);
            else {
                mp.set(t.charAt(i),mp.get(t.charAt(i))-1);
            }
        }
        for(let i=0;i<s.length;i++) {
            if(mp.get(s.charAt(i))!=0) return false;
        }
        for(let i=0;i<t.length;i++) {
            if(mp.get(t.charAt(i))!=0) return false;
        }
        return true;
    }
}
