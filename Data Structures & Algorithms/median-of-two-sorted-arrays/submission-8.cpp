class Solution {
public:
    double findNthNumber(vector<int>& nums1,vector<int>& nums2,int N) {
    // cout<<"finding "<<N<<"th number\n";
    int n=nums1.size(),m=nums2.size(),l=0,r=min(N,n);
    while(l<=r)
    {
        int have=(l+r)/2,need=N-have,large=INT_MIN,small=INT_MAX;
        // cout<<"have: "<<have<<" need: "<<need<<"\n";
        if(m<need)
        {
            l=have+1;
            continue;
        }
        if(have>0)
            large=nums1[have-1];
        if(need>0)
            large=max(large,nums2[need-1]);

        if(have<n)
            small=nums1[have];
        if(need<m)
            small=min(small,small);
        
        if(large<=small)
        {
            // cout<<"returning: "<<large<<"\n";
            return large;
        }
        else
        {
            if(have>0)
            {
                if(nums1[have-1]>=nums2[need-1])
                    r=have-1;
                else
                    l=have+1;
            }
        }
    }
    return 0;

}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size(),m=nums2.size();
    if((n+m)%2==1)
        return findNthNumber(nums1,nums2,(((n+m)/2)+1));
    double n1=findNthNumber(nums1,nums2,(((n+m)/2))),
    n2=findNthNumber(nums1,nums2,(((n+m)/2)+1)),
    ans=(n1+n2)/2;

    // cout<<"n1: "<<n1<<" n2: "<<n2<<"\n";
    // cout<<"ans: "<<ans<<"\n";
    return ans;
}
};
