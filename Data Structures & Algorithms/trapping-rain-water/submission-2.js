class Solution {
    min(a,b) {
        if(a<b) return a;
        return b;
    }
    max(a,b) {
        if(a>b) return a;
        return b;
    }
    trap(height) {
        const n=height.length;
        const left=[],right=[];
        let ans=0;
        left.length=n; right.length=n;
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(let i=1;i<n;i++)
            left[i]=this.max(left[i-1],height[i]);
        for(let i=n-2;i>=0;i--)
            right[i]=this.max(right[i+1],height[i]);
        for(let i=1;i<n-1;i++) {
            let mn=this.min(left[i-1],right[i+1]);
            
            if(mn>height[i])
                ans+=(mn-height[i]);
        }
        return ans;
    }
}
