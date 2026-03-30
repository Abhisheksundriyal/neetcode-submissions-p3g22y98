class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        unordered_set<string> mySet;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int have=nums[i]+nums[j],need=-have,l=j+1,r=n-1,idx=-1;
                vector<int> temp;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(nums[mid]==need)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(need);
                        break;
                    }
                    else if(nums[mid]>need)
                        r=mid-1;
                    else
                        l=mid+1;
                }
                if(temp.size())
                {
                    sort(temp.begin(),temp.end());
                    string key=to_string(temp[0])+to_string(temp[1])+to_string(temp[2]);
                    if(mySet.find(key)==mySet.end())
                    {
                        mySet.insert(key);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};
