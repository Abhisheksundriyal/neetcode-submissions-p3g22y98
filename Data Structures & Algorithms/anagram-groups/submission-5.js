class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let mp = new Map();
        for(let i=0;i<strs.length;i++) {
            let temp = strs[i].split("").sort().join("");
            if(!mp.has(temp))
                mp.set(temp,[]);
            mp.get(temp).push(strs[i]);
        }
        return [...mp.values()];
    }

}
