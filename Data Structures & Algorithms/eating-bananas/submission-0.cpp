class Solution {
public:
    int solve(vector<int>& piles,int k) {
    int ans=0;
    for(int i=0;i<piles.size();i++)
    {
        int temp=piles[i]/k;
        if(piles[i]%k!=0)
            temp++;
        ans+=temp;
    }
    return ans;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int r=1,n=piles.size(),l=1,ans;
    for(int i=0;i<n;i++)
        r=max(r,piles[i]);
    while(l<=r)
    {
        int mid=(l+r)/2,count=solve(piles,mid);
        // cout<<"mid: "<<mid<<" count: "<<count<<"\n";
        if(count<=h)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
};
