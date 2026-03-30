class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,num=(1 << 31);  
        for(int i=0;i<32;i++)
        {
            int temp=(1 << i);
            if((temp & n)!=0)
                ans+=num;
            num=num/2;
        }
        return ans;
    }
};
