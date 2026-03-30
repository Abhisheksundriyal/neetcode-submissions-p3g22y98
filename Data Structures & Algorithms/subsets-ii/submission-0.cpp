class Solution {
public:

    void recur(vector<int>& nums,int n,int idx,vector<int> curr,vector<vector<int>>& ans) {
        if(idx==n)
            return;
        
        int next=-1;
        for(int i=idx+1;i<n;i++)
        {
            if(nums[i]!=nums[idx])
            {
                next=i;
                break;
            }
        }
        if(next!=-1)
            recur(nums,n,next,curr,ans);
        curr.push_back(nums[idx]);
        ans.push_back(curr);
        recur(nums,n,idx+1,curr,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        ans.push_back(curr);
        recur(nums,n,0,curr,ans);
        return ans;
    }
};
