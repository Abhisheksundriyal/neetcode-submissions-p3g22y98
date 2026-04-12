class Solution {
public:
    bool check(vector<int>& nums,vector<vector<int>>& dp,int l,int sum,int k) {
        if(l>=nums.size() && k==0) return true;
        if((nums.size()-l)<k) return false;
        if(dp[l][k]!=-1) return dp[l][k];
        int ans=0,curr=0;
        for(int i=l;i<(int)nums.size();i++) {
            curr+=nums[i];
            if(curr<=sum && check(nums,dp,i+1,sum,k-1)) {
                ans=1;
                break;
            }
        }
        return dp[l][k]=ans;
    }
    bool solve(vector<int>& nums,int sum,int k) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return check(nums,dp,0,sum,k);

    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),ans=n;
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<n;i++) r+=nums[i];
        cout<<"l: "<<l<<" r: "<<r<<"\n";
        while(l<=r) {
            int mid=(l+r)/2;
            if(solve(nums,mid,k)) {
                ans=mid;
                r=mid-1;
            } else l=mid+1;
            // if(check(nums,dp,0,mid,k)) {
            //     ans=mid;
            //     r=mid-1;
            // } else l=mid+1;
        }
        return ans;
    }
};