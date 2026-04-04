class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size(),l=0;
        multiset<int> mySet;
        for(int i=0;i<n;i++) {
            
            if(mySet.size()>k) {
                mySet.erase(mySet.find(nums[l]));
                l++;
            }
            if(mySet.find(nums[i])!=mySet.end()) return true;


            mySet.insert(nums[i]);
        }
        return false;
    }
};