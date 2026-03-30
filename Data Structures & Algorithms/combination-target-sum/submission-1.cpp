class Solution {
public:
    vector<vector<int>> ans;

void recur(int idx,vector<int> curr,int sum,vector<int>& nums,int target) {
    // cout<<"sum: "<<sum<<"\n";
    if(sum==target)
    {
        ans.push_back(curr);
        return;
    }

    for(int i=idx;i<nums.size();i++)
    {
        if(sum+nums[i]>target)
            return;
        curr.push_back(nums[i]);
        recur(i,curr,sum+nums[i],nums,target);
        curr.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    recur(0,{},0,nums,target);
    return ans;
}
};
