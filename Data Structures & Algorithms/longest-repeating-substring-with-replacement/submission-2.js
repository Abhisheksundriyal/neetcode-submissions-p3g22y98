class Solution {
    /**
     * @param {string} s
     * @param {number} k
     * @return {number}
     */
    characterReplacement(s, k) {
        const n=s.length;
        const arr=[];
        arr.length=n;
        let ans=0;
        for(let i=0;i<n;i++) {
            let idx=s.charCodeAt(i)-'A'.charCodeAt(0);
            arr[i]=[];
            for(let j=0;j<26;j++){
                arr[i].push(0);
                if(i>0)
                    arr[i][j]+=arr[i-1][j];
            }
            arr[i][idx]++;
        }
        
        for(let i=0;i<n;i++) {
            for(let j=i+1;j<n;j++) {
                for(let c='A'.charCodeAt(0);c<='Z'.charCodeAt(0);c++) {
                    // let ch=String.fromCharCode(c);
                    let idx=c-'A'.charCodeAt(0);
                    let occ=arr[j][idx];
                    if(i>0) occ-=arr[i-1][idx];
                    let temp=(j-i+1)-occ;
                    if(temp<=k) {
                        if((j-i+1)>ans) ans=(j-i+1);
                    }
                }
            }
        }


        return ans;
    }
}
