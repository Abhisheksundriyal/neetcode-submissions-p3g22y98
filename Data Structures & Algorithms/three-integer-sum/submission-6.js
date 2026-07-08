class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        nums.sort((a,b) => {
            if(a<b) return -1;
            else if(a>b) return 1;
            return 0;
        })
        console.log(nums);
        const ans=[];
        const n=nums.length;
        for(let i=0;i<n;i++) {
            let target=nums[i]*(-1),l=i+1,r=n-1;
            if(i-1>=0 && nums[i]==nums[i-1]) continue;
            while(l<r) {
                let sum=nums[l]+nums[r];
                if(sum<target)
                    l++;
                else if(sum>target)
                    r--;
                else {
                    ans.push([nums[i],nums[l],nums[r]]);
                    l++;
                    while(l<n && nums[l]==nums[l-1]) l++;
                    r--;
                    while(r>=0 && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
}
