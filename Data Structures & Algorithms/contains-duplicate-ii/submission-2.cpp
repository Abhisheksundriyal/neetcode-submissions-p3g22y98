class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            // cout<<"i: "<<i<<"\n";
            for(int j=i+1;abs(i-j)<=k && j<n;j++) {
                // cout<<"j: "<<j<<"\n";
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
    }
};