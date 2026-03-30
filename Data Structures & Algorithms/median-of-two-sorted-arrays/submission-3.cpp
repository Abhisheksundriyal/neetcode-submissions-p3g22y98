class Solution {
public:
    int countEqual(vector<int>& nums,int target)
{
    int idxl=0,idxr=-1,l=0,r=nums.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]==target)
            idxl=mid;
        if(nums[mid]>=target)
            r=mid-1;
        else
            l=mid+1;
    }
    l=0;
    r=nums.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]==target)
            idxr=mid;
        if(nums[mid]<=target)
            l=mid+1;
        else
            r=mid-1;
    }
    return idxr-idxl+1;
}

int countSmall(vector<int>& nums,int target)
{
    int l=0,r=nums.size()-1,idx=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]<target)
        {
            idx=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return idx+1;
}

int findNthNumber(vector<int>& nums1,vector<int>& nums2,int N)
{
    cout<<"N: "<<N<<"\n";
    int l=0,r=nums1.size()-1;
    while(l<=r)
    {
        // cout<<"l: "<<l<<" r: "<<r<<"\n";
        int mid=(l+r)/2,pos=mid+1,countS=countSmall(nums2,nums1[mid]),countE=countEqual(nums2,nums1[mid]);
        // cout<<"mid: "<<mid<<"\n";
        // cout<<"num: "<<nums1[mid]<<"\n";
        // cout<<"pos: "<<pos<<"\n";
        // cout<<"countS: "<<countS<<"\n";
        // cout<<"countE: "<<countE<<"\n";
        if(N>=mid+1+countS && N<=mid+1+countS+countE)
            return nums1[mid];
        else if(N<mid+1+countS)
            r=mid-1;
        else
            l=mid+1;
        // cout<<"after l: "<<l<<" r: "<<r<<"\n";
    }
    l=0;
    r=nums2.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2,pos=mid+1,countS=countSmall(nums1,nums2[mid]),countE=countEqual(nums1,nums2[mid]);
        if(N>=mid+1+countS && N<=mid+1+countS+countE)
            return nums2[mid];
        else if(N<mid+1+countS)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n=nums1.size(),m=nums2.size();
    if((n+m)%2==1)
    {
        int N=((n+m)/2)+1;
        // cout<<"N: "<<N<<"\n";
        return findNthNumber(nums1,nums2,N);
    }
    int N1=((n+m)/2),N2=N1+1;
    // cout<<"N1: "<<N1<<" N2: "<<N2<<"\n";
    double a=findNthNumber(nums1,nums2,N1),b=findNthNumber(nums1,nums2,N2),ans=(a+b)/2;
    // cout<<"a: "<<a<<" b: "<<b<<"\n";
    if(ans<0)
        ans=0;
    return ans;
}
};
