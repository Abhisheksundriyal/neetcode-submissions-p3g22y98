class Solution {
public:
    void recur(vector<int>& nums,int idx,vector<int> curr,vector<vector<int>>& ans) {
    if(curr.size()!=0)
        ans.push_back(curr);
    for(int i=idx;i<nums.size();i++)
    {
        curr.push_back(nums[i]);
        recur(nums,i+1,curr,ans);
        curr.pop_back();
        int idx=i;
        while(idx<nums.size() && nums[idx]==nums[i])
            idx++;
        i=idx-1;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<vector<int>> ans={{}};
    recur(nums,0,{},ans);
    return ans;
}
};
