class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            if(myMap.find(need)!=myMap.end())
                return {myMap[need],i};
            myMap[nums[i]]=i;
        }
        return {};
    }
};
