class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    vector<pair<int,int>> q;
    vector<int> ans(queries.size());
    int idx=0;
    for(int i=0;i<queries.size();i++)
        q.push_back({queries[i],i});
    sort(q.begin(),q.end());
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<q.size();i++)
    {
        pair<int,int> temp=q[i];
        while(idx<intervals.size() && intervals[idx][0]<=temp.first)
        {
            minHeap.push({intervals[idx][1]-intervals[idx][0]+1,intervals[idx][1]});
            idx++;
        } 
        while(!minHeap.empty() && minHeap.top().second<temp.first)
            minHeap.pop();
        if(minHeap.empty())
            ans[temp.second]=-1;
        else
            ans[temp.second]=minHeap.top().first;
    }
    return ans;
}
};
