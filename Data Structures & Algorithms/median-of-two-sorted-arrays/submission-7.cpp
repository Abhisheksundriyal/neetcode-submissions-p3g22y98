class Solution {
public:
    double findNthValue(vector<int>& nums1,vector<int>& nums2,int x) {
    // cout<<"finding: "<<x<<"th value\n";
    int n=nums1.size(),m=nums2.size(),l=0,r=min(n,x);
    double ans;
    while(l<=r)
    {
        // cout<<"l: "<<l<<" r: "<<r<<"\n";
        int have=(l+r)/2,need=x-have;
        // cout<<"have: "<<have<<"\n";
        if(need<=m)
        {
            // cout<<"need: "<<need<<"\n";
            int small=INT_MIN,large=INT_MAX;
            if(have>0)
                small=max(small,nums1[have-1]);
            if(need>0)
                small=max(small,nums2[need-1]);
            if(have<n)
                large=min(large,nums1[have]);
            if(need<m)
                large=min(large,nums2[need]);
            // cout<<"small: "<<small<<" large: "<<large<<"\n";
            if(small<=large)
            {
                ans=small;
                break;
            }
            else
            {
                int large1=0,large2=0;
                if(have>0)
                    large1=nums1[have-1];
                if(need>0)
                    large2=nums2[need-1];
                // cout<<"large1: "<<large1<<" large2: "<<large2<<"\n";
                if(large1>=large2)
                    r=have-1;
                else
                    l=have+1;
            }
        }
        else
            l=have+1;
    }
    return ans;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size(),m=nums2.size();
    if((n+m)%2==1)
        return findNthValue(nums1,nums2,((n+m)/2)+1);
    double ans=findNthValue(nums1,nums2,((n+m)/2))+findNthValue(nums1,nums2,((n+m)/2)+1);
    ans/=2;
    return ans;
}
};
