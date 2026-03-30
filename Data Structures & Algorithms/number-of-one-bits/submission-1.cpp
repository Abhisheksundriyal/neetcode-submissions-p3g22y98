class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0,num=1;
        while(num<=n)
        {
            if((n & num)!=0)
                count++;
            num=num*2;
        }
        return count;
    }
};
