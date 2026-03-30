class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
    stack<int> myStac;
    vector<int> L(n),R(n);
    for(int i=0;i<n;i++)
    {
        while(!myStac.empty() && heights[myStac.top()]>=heights[i])
            myStac.pop();
        if(myStac.empty())
            L[i]=0;
        else
            L[i]=myStac.top()+1;
        myStac.push(i);
    }
    while(!myStac.empty())
        myStac.pop();
    for(int i=n-1;i>=0;i--)
    {
        while(!myStac.empty() && heights[myStac.top()]>=heights[i])
            myStac.pop();
        if(myStac.empty())
            R[i]=n-1;
        else
            R[i]=myStac.top()-1;
        myStac.push(i);
    }
    for(int i=0;i<n;i++)
    {
        int temp=(R[i]-L[i]+1)*heights[i];
        // cout<<"L: "<<L[i]<<" R[i]: "<<R[i]<<"\n";
        ans=max(ans,temp);
    }
    return ans;
    }
};
