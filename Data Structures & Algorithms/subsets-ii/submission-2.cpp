class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int n,int idx,vector<int>& curr) {
        if(idx>=n)
        {
            ans.push_back(curr);
            return;
        }
        int r=idx;
        while(r<n && nums[r]==nums[idx])
            r++;
        recur(nums,n,r,curr);
        for(int i=idx;i<r;i++)
        {
            curr.push_back(nums[i]);
            recur(nums,n,r,curr);
        }
        while(curr.size()>0 && curr[curr.size()-1]==nums[idx])
            curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        recur(nums,nums.size(),0,curr);
        return ans;
    }
};
