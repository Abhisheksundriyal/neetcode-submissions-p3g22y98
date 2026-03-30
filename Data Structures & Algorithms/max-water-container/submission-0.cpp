class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,ans=0;
        while(l<r)
        {
            int temp=(r-l)*min(heights[l],heights[r]);
            ans=max(ans,temp);
            if(heights[l]<=heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
