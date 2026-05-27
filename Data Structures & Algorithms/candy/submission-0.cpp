class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=0;
        vector<int> nums(n,1);
        for(int i=1;i<n;i++) {
            while(ratings[i]>ratings[i-1] && nums[i]<=nums[i-1]) nums[i]++;
        }
        for(int i=n-2;i>=0;i--) {
            while(ratings[i]>ratings[i+1] && nums[i]<=nums[i+1]) nums[i]++;
        }
        for(int i=0;i<n;i++) sum+=nums[i];
        return sum;
    }
};