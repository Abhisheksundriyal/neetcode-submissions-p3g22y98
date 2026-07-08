class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const mp = new Map();
        for(let i=0;i<nums.length;i++) {
            if(mp.has(nums[i]))
                mp.set(nums[i],mp.get(nums[i])+1);
            else
                mp.set(nums[i],1);
        }
        const temp=[];
        for(const [key, value] of mp) {
            temp.push([key,value]);
        }
        temp.sort((a,b) => {
            if(a[1]>b[1]) return -1;
            else if(b[1]>a[1]) return 1;
            return 0;
        });
        const ans=[];
        for(let i=0;i<k;i++)
            ans.push(temp[i][0]);
        return ans;
    }
}
