class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int n,int idx,int sum,int target,vector<int>& curr) {
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
        if(idx>=n || sum>target)
            return;
        int r=idx,newSum=sum;
        while(r<n && nums[r]==nums[idx])
            r++;
        recur(nums,n,r,sum,target,curr);
        for(int i=idx;i<r;i++)
        {
            newSum+=nums[i];
            curr.push_back(nums[i]);
            recur(nums,n,r,newSum,target,curr);
        }
        while(curr.size()>0 && curr[curr.size()-1]==nums[idx])
            curr.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        recur(candidates,candidates.size(),0,0,target,curr);
        return ans;
    }
};
