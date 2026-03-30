class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mySet;
        int idx=0,n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            mySet.insert(nums[i]);
            if(mySet.size()==k)
            {
                auto itr=mySet.rbegin();
                ans.push_back(*itr);
            }
            else if(mySet.size()>k)
            {
                auto itr=mySet.find(nums[idx]);
                mySet.erase(itr);
                idx++;
                auto itr2=mySet.rbegin();
                ans.push_back(*itr2);
            }
        }
        return ans;
    }
};
