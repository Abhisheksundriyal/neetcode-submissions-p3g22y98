class Solution {
public:
    int solve(vector<int>& piles,int k) {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            int temp=piles[i]/k;
            ans+=temp;
            if(piles[i]%k!=0)
                ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9,ans=r;
        while(l<=r)
        {
            int k=(l+r)/2,temp=solve(piles,k);
            if(temp<=h)
            {
                ans=min(ans,k);
                r=k-1;
            }
            else
                l=k+1;
        }
        return ans;
    }
};
