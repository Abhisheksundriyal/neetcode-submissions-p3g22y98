class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,slow1=0,fast=0;
        while(1)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow)
                break;
        }
        while(1)
        {
            slow=nums[slow];
            slow1=nums[slow1];
            if(slow==slow1)
                break;
        }
        return slow;

    }
};
