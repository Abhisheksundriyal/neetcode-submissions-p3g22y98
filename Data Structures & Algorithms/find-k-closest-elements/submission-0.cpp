class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int l=0,r=0,n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(nums[i]<=x) l=i;
        }
        r=l+1;
        for(int i=0;i<k;i++) {
            if(l>=0 && r<n) {
                if((x-nums[l])<=(nums[r]-x)) ans.push_back(nums[l--]);
                else ans.push_back(nums[r++]);
            }
            else if(l>=0)
                ans.push_back(nums[l--]);
            else
                ans.push_back(nums[r++]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};