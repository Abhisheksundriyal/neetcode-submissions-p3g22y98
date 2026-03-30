class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR=0;
        for(int i=0;i<nums.size();i++)
        {
            XOR=(XOR ^ nums[i]);
            XOR=(XOR ^ i);
        }
        XOR=(XOR ^ nums.size());
        return XOR;
    }
};
