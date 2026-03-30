class Solution {
public:
    void dfs(int node,vector<vector<int>>& children,
    vector<int>& VIS,bool& isPossible,vector<int>& ans)
{
    VIS[node]=1;
    for(int i=0;i<children[node].size();i++)
    {
        int newNode=children[node][i];
        
        if(VIS[newNode]==0)
            dfs(newNode,children,VIS,isPossible,ans);
        if(VIS[newNode]==1)
            isPossible=false;
    }
    VIS[node]=2;
    ans.push_back(node);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> children(numCourses);
    vector<int> VIS(numCourses,0);
    bool isPossible=true;
    vector<int> ans;
    for(int i=0;i<prerequisites.size();i++)
    {
        int a=prerequisites[i][0],b=prerequisites[i][1];
        children[b].push_back(a);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(VIS[i]==0)
            dfs(i,children,VIS,isPossible,ans);
    }
    if(!isPossible)
        ans={};
    reverse(ans.begin(),ans.end());
    return ans;
}
};
