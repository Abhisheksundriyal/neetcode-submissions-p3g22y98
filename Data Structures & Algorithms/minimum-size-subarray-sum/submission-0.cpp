class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),ans=0,l=0,sum=0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            while(l<i) {
                int newSum=sum-nums[l];
                if(newSum>=target) {
                    l++;
                    sum=newSum;
                }
                else
                    break;
            }
            if(sum>=target) {
                int len=i-l+1;
                if(ans==0) ans=len;
                else ans=min(ans,len);
            }
        }
        return ans;
    }
};