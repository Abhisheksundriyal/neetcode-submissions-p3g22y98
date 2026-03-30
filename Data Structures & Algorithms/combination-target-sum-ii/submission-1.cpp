class Solution {
public:
    vector<vector<int>> ans;

void recur(vector<int>& candidates,int idx,vector<int> curr,int sum,int target) {
    if(sum==target)
    {
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<candidates.size();i++)
    {
        if(i>idx && candidates[i]==candidates[i-1])
            continue;
        if(sum+candidates[i]>target)
            return;
        curr.push_back(candidates[i]);
        recur(candidates,i+1,curr,sum+candidates[i],target);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    // cout<<"candidates: ";
    // for(int i=0;i<candidates.size();i++)
    //     cout<<candidates[i]<<" ";
    // cout<<"\n";
    recur(candidates,0,{},0,target);
    return ans;
}
};
