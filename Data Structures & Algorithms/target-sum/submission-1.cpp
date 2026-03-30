class Solution {
public:
    int recur(vector<int>& nums,map<pair<int,int>,int>& myMap,int n,int idx,int sum,int target) {
    if(idx==n)
    {
        if(sum==target)
            return myMap[{idx,sum}]=1;
        else
            return myMap[{idx,sum}]=0;
    }
    int a=sum+nums[idx],b=sum-nums[idx],ans=0;
    if(myMap.find({idx+1,a})==myMap.end())
        recur(nums,myMap,n,idx+1,a,target);
    ans+=myMap[{idx+1,a}];
    if(myMap.find({idx+1,b})==myMap.end())
        recur(nums,myMap,n,idx+1,b,target);
    ans+=myMap[{idx+1,b}];
    return myMap[{idx,sum}]=ans;
}


int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    map<pair<int,int>,int> myMap;
    return recur(nums,myMap,n,0,0,target);
}
};
