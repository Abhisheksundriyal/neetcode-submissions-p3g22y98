class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    binarySearch(l,r,target,nums) {
        while(l<=r) {
            let mid=Math.floor((l+r)/2);
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                r=mid-1;
            else return mid;
        }
        return -1;
    }
    twoSum(numbers, target) {
        let n=numbers.length;
        for(let i=0;i<n-1;i++) {
            let idx=this.binarySearch(i+1,n-1,target-numbers[i],numbers);
            if(idx!=-1) return [i+1,idx+1];
        }
        return [-2,-2];
    }
}
