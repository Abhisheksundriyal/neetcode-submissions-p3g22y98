class Solution {
    twoSum(numbers, target) {
        let n=numbers.length;
        let l=0,r=n-1,sum=numbers[l]+numbers[r];
        while(l<r) {
            sum=numbers[l]+numbers[r];
            if(sum>target) r--;
            else if(sum<target) l++;
            else return [l+1,r+1];
        }
        return [-2,-2];
    }
}
