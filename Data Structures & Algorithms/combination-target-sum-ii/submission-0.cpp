class Solution {
public:

    void recur(vector<int>& candidates,int n,int idx,int sum,int target,vector<int> curr,vector<vector<int>>& ans) {
        if(idx==n)
        {
            if(sum==target)
                ans.push_back(curr);
            return;
        }
        if(sum>target)
            return;
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
            
        int next=-1;
        for(int i=idx+1;i<n;i++)
        {
            if(candidates[i]!=candidates[idx])
            {
                next=i;
                break;
            }
        }
        if(next!=-1)
            recur(candidates,n,next,sum,target,curr,ans);
        curr.push_back(candidates[idx]);
        sum+=candidates[idx];
        recur(candidates,n,idx+1,sum,target,curr,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        recur(candidates,n,0,0,target,curr,ans);
        return ans;
    }
};
