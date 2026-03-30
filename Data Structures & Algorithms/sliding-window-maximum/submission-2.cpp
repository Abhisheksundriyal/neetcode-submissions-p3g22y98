class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mySet;
        int idx=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            mySet.insert(nums[i]);
            if(mySet.size()>k)
            {
                auto itr=mySet.find(nums[idx]);
                mySet.erase(itr);
                idx++;
            }
            if(mySet.size()==k)
            {
                auto itr=mySet.rbegin();
                ans.push_back(*itr);
            }
        }
        return ans;
    }
};
