class Solution {
public:
    int solve(vector<int>& point)
{
    int x=point[0],y=point[1],ans=0;
    ans=(x*x)+(y*y);
    return ans;
}

// void printHeap(priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> maxHeap)
// {
//     cout<<"heap: ";
//     while(!maxHeap.empty())
//     {
//         cout<<maxHeap.top().second[0]<<" . "<<maxHeap.top().second[1]<<" ";
//         maxHeap.pop();
//     }
//     cout<<"\n";
// }

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n=points.size();
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> maxHeap;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        pair<int,vector<int>> temp={solve(points[i]),points[i]};
        if(maxHeap.size()<k)
            maxHeap.push(temp);
        else
        {
            if(temp.first<maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push(temp);
            }
        }
        // printHeap(maxHeap);
    }
    while(!maxHeap.empty())
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
}
};
