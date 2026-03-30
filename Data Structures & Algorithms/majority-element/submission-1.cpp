class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],occ=1;
        for(int i=1;i<(int)nums.size();i++) {
            if(nums[i]==ans) occ++;
            else occ--;

            if(occ<0) ans=nums[i];
        }
        // cout<<"occ: "<<occ<<"\n";
        return ans;
    }
};