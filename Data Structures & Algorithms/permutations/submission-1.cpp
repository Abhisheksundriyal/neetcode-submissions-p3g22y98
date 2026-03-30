class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,unordered_set<int> mySet,vector<int> curr) {
        if(mySet.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mySet.find(i)==mySet.end())
            {
                curr.push_back(nums[i]);
                mySet.insert(i);
                recur(nums,mySet,curr);
                curr.pop_back();
                mySet.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> mySet;
        recur(nums,mySet,{});
        return ans;
    }
};
