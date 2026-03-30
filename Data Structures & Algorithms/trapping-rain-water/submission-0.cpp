class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++)
        {
            left[i]=height[i];
            if(i>0)
                left[i]=max(left[i],left[i-1]);
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i]=height[i];
            if(i<n-1)
                right[i]=max(right[i],right[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            int temp=min(left[i-1],right[i+1]);
            if(temp>height[i])
                ans+=temp-height[i];
        }
        return ans;
    }
};
