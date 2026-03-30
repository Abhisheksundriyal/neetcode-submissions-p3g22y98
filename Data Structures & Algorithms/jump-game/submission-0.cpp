class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),idx=n-1;
        for(int i=n-2;i>=0;i--)
        {
            int need=(idx-i);
            if(nums[i]>=need)
                idx=i;
        }
        if(idx==0)
            return true;
        return false;
    }
};
