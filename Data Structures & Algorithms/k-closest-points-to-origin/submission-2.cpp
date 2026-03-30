class Solution {
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>> maxHeap;
    int dist(vector<int>& point1,vector<int>& point2) {
        return (((point1[0]-point2[0])*(point1[0]-point2[0]))
                +((point1[1]-point2[1])*(point1[1]-point2[1])));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> origin={0,0};
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++)
        {
            maxHeap.push({dist(origin,points[i]),points[i]});
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
        while(!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
