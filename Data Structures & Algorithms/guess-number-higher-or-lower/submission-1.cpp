/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * long long guess(long long num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,r=n,ans=-1;
        while(l<=r) {
            long long mid=(l+r)/2,res=guess(mid);
            if(res==0) {
                ans=mid;
                break;
            }
            else if(res==-1) r=mid-1;
            else l=mid+1;
        }
        return (int)ans;
    }
};