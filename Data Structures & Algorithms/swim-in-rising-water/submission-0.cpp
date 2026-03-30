class Solution {
public:
    bool valid(int i,int j,int n,vector<vector<int>>& VIS) {
    if(i>=0 && i<n && j>=0 && j<n && VIS[i][j]==0)
    {
        VIS[i][j]=1;
        return true;
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size(),ans=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
    minHeap.push({grid[0][0],{0,0}});
    vector<vector<int>> VIS(n);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(n,0);
        VIS[i]=temp;
    }
    while(!minHeap.empty())
    {
        pair<int,pair<int,int>> p=minHeap.top();
        minHeap.pop();
        pair<int,pair<int,int>> temp;
        ans=p.first;
        int i=p.second.first,j=p.second.second;
        if(p.second.first==n-1 && p.second.second==n-1)
            break;
        if(valid(i,j+1,n,VIS))
            minHeap.push({max(ans,grid[i][j+1]),{i,j+1}});
        if(valid(i+1,j,n,VIS))
            minHeap.push({max(ans,grid[i+1][j]),{i+1,j}});
        if(valid(i,j-1,n,VIS))
            minHeap.push({max(ans,grid[i][j-1]),{i,j-1}});
        if(valid(i-1,j,n,VIS))
            minHeap.push({max(ans,grid[i-1][j]),{i-1,j}});
    }
    return ans;
}
};
