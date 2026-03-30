class Solution {
public:
    int trap(vector<int>& height) {
    int ans=0,n=height.size();
    vector<int> L(n),R(n);
    for(int i=0;i<n;i++)
    {
        L[i]=height[i];
        if(i>0)
            L[i]=max(L[i],L[i-1]);
    }
    for(int i=n-1;i>=0;i--)
    {
        R[i]=height[i];
        if(i<n-1)
            R[i]=max(R[i],R[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        int small=min(L[i-1],R[i+1]);
        if(small>height[i])
            ans+=(small-height[i]);
    }
    return ans;
}
};
