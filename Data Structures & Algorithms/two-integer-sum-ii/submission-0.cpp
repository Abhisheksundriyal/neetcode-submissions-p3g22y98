class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        for(int i=0;i<n-1;i++)
        {
            int need=target-numbers[i],l=i+1,r=n-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(numbers[mid]==need)
                    return {i+1,mid+1};
                else if(numbers[mid]>need)
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return {};
    }
};
