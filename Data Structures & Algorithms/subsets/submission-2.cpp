class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int n,int idx,vector<int> curr) {
        if(idx==n)
        {
            ans.push_back(curr);
            return;
        }
        recur(nums,n,idx+1,curr);
        curr.push_back(nums[idx]);
        recur(nums,n,idx+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        recur(nums,nums.size(),0,{});
        return ans;
    }
};
