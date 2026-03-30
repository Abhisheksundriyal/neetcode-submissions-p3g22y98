class Solution {
public:
    void dfs(vector<vector<int>>& children,vector<int>& VIS,int node) {
    // cout<<"node: "<<node<<"\n";
    VIS[node]=1;
    int count=0,n=children[node].size();
    for(int i=0;i<n;i++)
    {
        int next=children[node][i];
        if(VIS[next]==0)
            dfs(children,VIS,next);
        if(VIS[next]!=2)
            count++;
    }
    if(count==0)
        VIS[node]=2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> children(numCourses);
    vector<int> VIS(numCourses,0);
    bool ans=true;
    int num=1;
    for(int i=0;i<prerequisites.size();i++)
    {
        int child=prerequisites[i][0],parent=prerequisites[i][1];
        children[parent].push_back(child);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(VIS[i]==0)
            dfs(children,VIS,i);
        // cout<<"VIS[i]: "<<VIS[i]<<"\n";
        if(VIS[i]!=2)
            return false;
    }
    return true;
}
};
