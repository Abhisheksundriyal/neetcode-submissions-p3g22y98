class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> maxHeap;
    vector<vector<int>> ans;
    int n=points.size();
    for(int i=0;i<n;i++)
    {
        int x=points[i][0],y=points[i][1],d=(x*x)+(y*y);
        if(maxHeap.size()<k)
            maxHeap.push({d,points[i]});
        else
        {
            // int temp=maxHeap.top();
            if(maxHeap.top().first>d)
            {
                maxHeap.pop();
                maxHeap.push({d,points[i]});
            }
        }
    }
    while(!maxHeap.empty())
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
}
};
