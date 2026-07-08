class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        const left=[];
        const right=[];
        const ans=[];
        const n=nums.length;
        left.length=n; right.length=n;
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(let i=1;i<n;i++) {
            left[i]=left[i-1]*nums[i];
        }
        for(let i=n-2;i>=0;i--) {
            right[i]=right[i+1]*nums[i];
        }
        ans[0]=right[1];
        ans[n-1]=left[n-2];
        for(let i=1;i<n-1;i++) {
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
}
