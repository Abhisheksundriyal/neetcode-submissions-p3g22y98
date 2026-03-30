class Solution {
public:
    void recur(vector<int>& nums,int n,vector<int> curr,int idx,int sum,int target,vector<vector<int>>& ans) {
    if(idx>=n || sum>target)
        return;
    if(sum==target)
    {
        ans.push_back(curr);
        return;
    }
    recur(nums,n,curr,idx+1,sum,target,ans);
    curr.push_back(nums[idx]);
    sum+=nums[idx];
    recur(nums,n,curr,idx,sum,target,ans);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<int> curr;
    vector<vector<int>> ans;
    recur(nums,n,curr,0,0,target,ans);
    return ans;
}
};
