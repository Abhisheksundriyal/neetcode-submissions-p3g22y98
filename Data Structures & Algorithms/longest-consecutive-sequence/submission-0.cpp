class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ans=0;
    unordered_map<int,int> myMap;
    for(int i=0;i<n;i++)
    {
        if(myMap[nums[i]]==0)
        {
            myMap[nums[i]]=myMap[nums[i]-1]+1+myMap[nums[i]+1];
            myMap[nums[i]-myMap[nums[i]-1]]=myMap[nums[i]];
            myMap[nums[i]+myMap[nums[i]+1]]=myMap[nums[i]];
            ans=max(ans,myMap[nums[i]]);
        }
    }
    return ans;
    }
};
