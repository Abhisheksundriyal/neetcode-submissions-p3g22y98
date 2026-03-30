class Solution {
public:
    void dfs(vector<vector<int>>& children,vector<int>& VIS,int node,int num,bool& ans) {
    if(VIS[node]!=0)
    {
        if(VIS[node]==num)
            ans=false;
        return;
    }
    VIS[node]=num;
    int n=children[node].size();
    for(int i=0;i<n;i++)
    {
        int next=children[node][i];
        dfs(children,VIS,next,num,ans);
    }
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
        {
            dfs(children,VIS,i,num,ans);
            num++;
        }
    }
    return ans;
}
};
