class Solution {
public:
    double solve(double x,long long N) {
        if(N==0)
            return (double)1;
        if(N==1)
            return x;
        double ans=solve(x,N/2);
        ans=ans*ans;
        if(N%2==1)
            ans*=x;
        return ans;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0)
            N=-N;
        double ans=solve(x,N);
        if(n<0)
            ans=(1/ans);
        return ans;
    }
};