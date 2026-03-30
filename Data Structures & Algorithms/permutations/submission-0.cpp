class Solution {
public:

    void recur(vector<int>& nums,int n,set<int>& VIS,vector<int>& curr,vector<vector<int>>& ans) {
        if(VIS.size()==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(VIS.find(i)==VIS.end())
            {
                vector<int> temp=curr;
                set<int> mySet=VIS;
                temp.push_back(nums[i]);
                mySet.insert(i);
                recur(nums,n,mySet,temp,ans);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        set<int> VIS;
        vector<vector<int>> ans;
        vector<int> curr;
        recur(nums,n,VIS,curr,ans);
        return ans;
    }
};
