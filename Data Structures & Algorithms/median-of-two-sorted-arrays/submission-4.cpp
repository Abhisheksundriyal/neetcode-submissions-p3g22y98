class Solution {
public:
    int findNthNum(vector<int>& nums1,vector<int>& nums2,int N)
{
    // cout<<"N: "<<N<<"\n";
    int l=0,r=N;
    if(nums1.size()<r)
        r=nums1.size();
    while(l<=r)
    {
        int mid=(l+r)/2,need=N-mid,large=INT_MAX,temp=INT_MIN;
        // cout<<"mid: "<<mid<<" need: "<<need<<"\n";
        // cout<<"nums1.size(): "<<nums1.size()<<" nums2.size(): "<<nums2.size()<<"\n";
        if(nums2.size()>=need)
        {
            
            if(mid<nums1.size() && mid>=0)
                large=nums1[mid];
            if(need<nums2.size() && need>=0)
                large=min(large,nums2[need]);

            if(mid>0 && (mid-1)<nums1.size())
                temp=nums1[mid-1];
            if(need>0 && (need-1)<nums2.size())
                temp=max(temp,nums2[need-1]);

            // cout<<"temp: "<<temp<<" large: "<<large<<"\n";

            if(large>=temp)
                return temp;
            else
            {
                int large1=INT_MIN,large2=INT_MIN;
                if(mid>0 && (mid-1)<nums1.size())
                    large1=nums1[mid-1];
                if(need>0 && (need-1)<nums2.size())
                    large2=nums2[need-1];
                // cout<<"large1: "<<large1<<" large2: "<<large2<<"\n";
                if(large1>=large2)
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        else
        {
            // cout<<"hello world\n";
            l=mid+1;
        }
    }
    return -1;
}

double findMedian(vector<int>& nums)
{
    if(nums.size()%2==1)
        return nums[nums.size()/2];
    double a=nums[nums.size()/2],b=nums[(nums.size()/2)-1],ans=(a+b)/2;
    if(ans<0)
        ans=0;
    return ans;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.size()==0 || nums2.size()==0)
    {
        if(nums1.size()==0 && nums2.size()==0)
            return 0;
        else if(nums1.size()==0)
            return findMedian(nums2);
        else
            return findMedian(nums1);
    }
    int n=nums1.size(),m=nums2.size();
    if((n+m)%2==1)
    {
        int N=((n+m)/2)+1;
        return findNthNum(nums1,nums2,N);
    }
    int N1=((n+m)/2),N2=N1+1;
    // cout<<"N1: "<<N1<<" N2: "<<N2<<"\n";
    double a=findNthNum(nums1,nums2,N1),b=findNthNum(nums1,nums2,N2),ans=(a+b)/2;
    // cout<<"a: "<<a<<" b: "<<b<<"\n";
    if(ans<0)
        ans=0;
    return ans;
}
};
