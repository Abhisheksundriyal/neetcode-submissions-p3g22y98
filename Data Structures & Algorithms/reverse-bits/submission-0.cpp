class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int p=31;
        for(int i=0;i<32;i++) {
            int temp=(1 << i);
            if((temp & n)!=0)
            {
                temp=(1 << p);
                ans+=temp;
            }
            p--;
        }
        return ans;
    }
};
