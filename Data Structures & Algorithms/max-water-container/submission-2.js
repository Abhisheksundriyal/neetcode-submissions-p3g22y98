class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    min(a,b) {
        if(a<b) return a;
        return b;
    }
    maxArea(heights) {
        let l=0,r=heights.length,ans=0;
        while(l<r) {
            let sum=(r-l)*this.min(heights[l],heights[r]);
            if(sum>ans) ans=sum;
            if(heights[l]<=heights[r]) l++;
            else r--;
        }
        return ans;
    }
}
