class Solution {
public:
    int reverse(int x) {
        long long ans=0,num=abs(x);
        while(num>0)
        {
            ans=(ans*10)+(num%10);
            num=num/10;
        }
        if(x<0)
            ans=ans*(-1);
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        return (int)ans;
    }
};
