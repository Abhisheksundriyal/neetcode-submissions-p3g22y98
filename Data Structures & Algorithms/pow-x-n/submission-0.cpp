class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        double ans=myPow(x,abs(n)/2);
        ans=ans*ans;
        if(abs(n)%2!=0)
            ans=ans*x;
        if(n<0)
            ans=1/ans;
        return ans;
    }
};
