class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> myMap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            myMap[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++)
        {
            int have=nums[i],need=target-have;
            if(myMap.find(need)!=myMap.end())
            {
                vector<int>& temp=myMap[need];
                if(have==need)
                {
                    if(myMap[need].size()>1)
                    {
                        ans.push_back(myMap[need][0]);
                        ans.push_back(myMap[need][1]);
                        break;
                    }
                }
                else
                {
                    ans.push_back(myMap[have][0]);
                    ans.push_back(myMap[need][0]);
                    break;
                }
            }
        }
        return ans;
    }
};
