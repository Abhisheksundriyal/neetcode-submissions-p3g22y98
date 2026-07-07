class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let x=-1,y=-1
        for(let i=0;i<nums.length;i++) {
            for(let j=i+1;j<nums.length;j++) {
                if(nums[i]+nums[j]==target) {
                    x=i; y=j;
                    break;
                }
            }
            if(x!=-1) break;
        }
        return [x,y];
    }
}
