class Solution {
public:
    bool check(vector<int>& weights,int days,int target) {
        int ans=0,n=weights.size(),curr=0;
        for(int i=0;i<n;i++) {
            if(weights[i]>target) return false;
            if(curr+weights[i]>target) {
                curr=weights[i];
                ans++;
                if(i==n-1) ans++;
            } else {
                if(i==n-1) ans++;
                curr+=weights[i];
            }
        }
        return (ans<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,n=weights.size();
        for(int i=0;i<n;i++) sum+=weights[i];
        int l=0,r=sum,ans;
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(weights,days,mid)) {
                ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        return ans;
    }
};