class Solution {
    max(a,b) {
        if(a>=b) return a;
        return b;
    }
    longestConsecutive(nums) {
        nums.sort((a, b) => {
            if(a<b) return -1;
            else if(b<a) return 1;
            return 0;
        });
        let ans=0;
        const mp = new Map();
        for(let i=0;i<nums.length;i++) {
            let val=1;
            if(mp.has(nums[i]-1)) {
                val+=mp.get(nums[i]-1);
            }
            if(mp.has(nums[i]))
                mp.set(nums[i],this.max(mp.get(nums[i]),val));
            else
                mp.set(nums[i],val);
            if(val>ans) ans=val;
        }
        return ans;
    }
}