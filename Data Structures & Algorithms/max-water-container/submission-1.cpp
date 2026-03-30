class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0,l=0,r=heights.size()-1;
        while(l<=r)
        {
            int area=min(heights[l],heights[r])*(r-l);
            ans=max(ans,area);
            if(heights[l]<=heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
