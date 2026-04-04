class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        int prev=-1;
        for(int i=0;i<(int)nums.size();i++) {
            if(nums[i]!=prev) {
                prev=nums[i];
                swap(nums[i],nums[idx++]);
                
            }
        }
        // cout<<"idx: "<<idx<<"\n";
        while(nums.size()<idx) nums.pop_back(); 
        return idx;
    }
};