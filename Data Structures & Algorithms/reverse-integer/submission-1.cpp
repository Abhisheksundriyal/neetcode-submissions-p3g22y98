class Solution {
public:
    int reverse(int x) {
        long long ans=0,num=x;
        if(num<0)
            num=-num;
        while(num>0)
        {
            ans=(ans*10)+(num%10);
            num=num/10;
        }
        if(x<0)
            ans=-ans;
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        return (int)ans;
    }
};
