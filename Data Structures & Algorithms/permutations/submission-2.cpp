class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int n,unordered_set<int>& VIS,vector<int>& curr) {
        if(VIS.size()==n) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(VIS.find(i)==VIS.end())
            {
                VIS.insert(i);
                curr.push_back(nums[i]);
                recur(nums,n,VIS,curr);
                VIS.erase(i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> VIS;
        vector<int> curr;
        recur(nums,n,VIS,curr);
        return ans;
    }
};
