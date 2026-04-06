class Solution {
public:
    int mySqrt(int x) {
        long long l=1,r=x,ans=0;
        while(l<=r) {
            // cout<<"l: "<<l<<" r: "<<r<<"\n";
            long long mid=(l+r)/2;
            if((mid*mid)<=x) {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return (int)ans;
    }
};