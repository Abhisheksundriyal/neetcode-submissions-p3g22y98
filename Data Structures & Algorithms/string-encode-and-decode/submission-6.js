class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let n=strs.length;
        let ans="";
        for(let i=0;i<n;i++) {
            let temp=strs[i].length;
            if(ans.length==0)
                ans+=temp+","+strs[i];
            else ans+=","+temp+","+strs[i];
        }
        return ans;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        let ans=[];
        let temp="";
        let idx=0;
        for(;idx<str.length;idx++) {
            if(str.charAt(idx)==',') {
                let n=parseInt(temp);
                let S="";
                for(let j=idx+1;j<=idx+n;j++)
                    S+=str.charAt(j);
                ans.push(S);
                idx+=(n+1);
                temp="";
            } else {
                temp+=str.charAt(idx);
            }
        }
        return ans;
    }
}