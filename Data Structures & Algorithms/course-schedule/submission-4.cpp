class Solution {
public:
    void dfs(int node,vector<vector<int>>& children,vector<int>& VIS,bool& ans) {
    VIS[node]=1;
    for(int i=0;i<children[node].size();i++)
    {
        int newNode=children[node][i];
        if(VIS[newNode]==0)
            dfs(newNode,children,VIS,ans);
        else if(VIS[newNode]==1)
            ans=false;
    }
    VIS[node]=2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> children(numCourses);
    vector<int> VIS(numCourses,0);
    bool ans=true;
    for(int i=0;i<prerequisites.size();i++)
    {
        int a=prerequisites[i][0],b=prerequisites[i][1];
        children[b].push_back(a);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(VIS[i]==0)
            dfs(i,children,VIS,ans);
    }
    return ans;
}
};
