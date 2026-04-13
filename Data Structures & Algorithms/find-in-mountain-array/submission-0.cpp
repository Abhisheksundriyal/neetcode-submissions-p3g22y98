/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPivot(MountainArray &mountainArr,int n) {
        int l=0,r=n-1,idx=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(mid==0 || mid==n-1) {
                l=mid+1;
                continue;
            }
            int a=mountainArr.get(mid-1),b=mountainArr.get(mid),c=mountainArr.get(mid+1);
            if(a<b && b<c)
                l=mid+1;
            else if(a>b && b>c)
                r=mid-1;
            else {
                idx=mid;
                break;
            }
        }
        return idx;
    }
    int binarySearch(MountainArray &mountainArr,int l,int r,int target,char ch) {
        int idx=-1;
        while(l<=r) {
            int mid=(l+r)/2,val=mountainArr.get(mid);
            if(val<target) {
                if(ch=='U')
                    l=mid+1;
                else
                    r=mid-1;
            }
            else if(val>target) {
                if(ch=='U')
                    r=mid-1;
                else
                    l=mid+1;
            }
            else {
                idx=mid;
                break;
            }
        }
        return idx;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length(),peak=findPivot(mountainArr,n);
        int idx1=binarySearch(mountainArr,0,peak,target,'U');
        int idx2=binarySearch(mountainArr,peak+1,n-1,target,'D');
        if(idx1!=-1) return idx1;
        if(idx2!=-1) return idx2;
        return -1;
    }
};