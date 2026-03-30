class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int temp=(1 << i);
            if((temp & n)!=0)
                ans++;
        }
        return ans;
    }
};
