class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),l=0;
        vector<int> ans;
        multiset<int> st;
        for(int i=0;i<n;i++) {
            st.insert(nums[i]);
            while(st.size()>k) {
                auto itr=st.find(nums[l]);
                l++;
                st.erase(itr);
            }
            if(st.size()==k) {
                auto itr=st.rbegin();
                ans.push_back(*itr);
            }
            
        }
        return ans;
    }
};
