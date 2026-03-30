class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=0;
        for(int i=0;i<(int)nums.size();i++) {
            if(nums[i]!=val) {
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        return idx;
    }
};