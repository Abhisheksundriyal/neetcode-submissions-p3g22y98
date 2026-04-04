class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        vector<vector<long long>> ans;
        set<vector<long long>> mySet;
        unordered_map<long long,vector<pair<long long,long long>>> mp;
        long long n=nums.size();
        mp[nums[0]+nums[1]].push_back({nums[0],nums[1]});
        for(long long i=2;i<n;i++) {
            for(long long j=i+1;j<n;j++) {
                long long sum=nums[i]+nums[j],need=target-sum;
                if(mp.find(need)==mp.end()) continue;
                // cout<<"i: "<<i<<" j: "<<j<<"\n";
                // cout<<"need: "<<need<<"\n";
                for(long long k=0;k<mp[need].size();k++) {
                    vector<long long> temp={mp[need][k].first,mp[need][k].second,nums[i],nums[j]};
                    sort(temp.begin(),temp.end());
                    if(mySet.find(temp)==mySet.end()) {
                        mySet.insert(temp);
                        ans.push_back(temp);
                    }
                }
            }
            for(long long j=i-1;j>=0;j--) {
                long long sum=nums[i]+nums[j];
                mp[sum].push_back({nums[i],nums[j]});
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<ans.size();i++) {
            vector<int> temp;
            for(int j=0;j<4;j++) {
                temp.push_back((int)ans[i][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};