class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
    vector<int> left(n),right(n);
    stack<pair<int,int>> myStac;
    myStac.push({-1,INT_MIN});
    for(int i=0;i<n;i++)
    {
        while(!myStac.empty() && myStac.top().second>=heights[i])
            myStac.pop();
        left[i]=myStac.top().first;
        myStac.push({i,heights[i]});
    }
    while(!myStac.empty())
        myStac.pop();
    myStac.push({n,INT_MIN});
    for(int i=n-1;i>=0;i--)
    {
        while(!myStac.empty() && myStac.top().second>=heights[i])
            myStac.pop();
        right[i]=myStac.top().first;
        myStac.push({i,heights[i]});
    }
    for(int i=0;i<n;i++)
    {
        int temp=((i-left[i])+(right[i]-i)-1)*heights[i];
        ans=max(ans,temp);
    }
    return ans;
    }
};
