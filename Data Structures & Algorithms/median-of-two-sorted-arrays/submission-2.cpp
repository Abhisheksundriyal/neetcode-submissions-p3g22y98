class Solution {
public:
    int countSmall2(vector<int>& nums,int target)
{
    int l=0,r=nums.size()-1,idx=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]<=target)
        {
            idx=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return idx+1;
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

int findNthNumber(vector<int>& nums1,vector<int>& nums2,int N,char ch)
{
    int l=0,r=nums1.size()-1,num=-1;
    while(l<=r)
    {
        int mid=(l+r)/2,count=mid+1;
        if(ch=='L')
            count+=countSmall2(nums2,nums1[mid]);
        else
            count+=countSmall(nums2,nums1[mid]);
        if(count==N)
            return nums1[mid];
        else if(count>N)
            r=mid-1;
        else
            l=mid+1;
    }
    l=0;
    r=nums2.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2,count=mid+1;
        if(ch=='L')
            count+=countSmall2(nums1,nums2[mid]);
        else
            count+=countSmall(nums1,nums2[mid]);

        if(count==N)
            return nums2[mid];
        else if(count>N)
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
        return findNthNumber(nums1,nums2,N,'L');
    }
    int N1=((n+m)/2),N2=N1+1;
    // cout<<"N1: "<<N1<<" N2: "<<N2<<"\n";
    double a=findNthNumber(nums1,nums2,N1,'L'),b=findNthNumber(nums1,nums2,N2,'R'),ans=(a+b)/2;
    // cout<<"a: "<<a<<" b: "<<b<<"\n";
    if(ans<0)
        ans=0;
    return ans;  
}
};
