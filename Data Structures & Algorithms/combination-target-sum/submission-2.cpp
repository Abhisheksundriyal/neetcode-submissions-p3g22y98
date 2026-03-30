class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int n,int idx,int sum,int target,vector<int>& curr){
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
        if(idx>=n || sum>target)
            return;
        recur(nums,n,idx+1,sum,target,curr);
        curr.push_back(nums[idx]);
        recur(nums,n,idx,sum+nums[idx],target,curr);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        recur(nums,nums.size(),0,0,target,curr);
        return ans;
    }
};
