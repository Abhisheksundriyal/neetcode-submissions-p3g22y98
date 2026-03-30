class Solution {
public:
    void recur(vector<vector<int>>& parents,int node,vector<int>& VIS,vector<int>& ans) {
    VIS[node]=1;
    int n=parents[node].size(),count=0;
    for(int i=0;i<n;i++)
    {
        int next=parents[node][i];
        if(VIS[next]==0)
            recur(parents,next,VIS,ans);
        if(VIS[next]!=2)
            count++;
    }
    if(count==0)
    {
        VIS[node]=2;
        ans.push_back(node);
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> parents(numCourses);
    vector<int> VIS(numCourses,0);
    vector<int> ans;
    for(int i=0;i<prerequisites.size();i++)
    {
        int child=prerequisites[i][0],parent=prerequisites[i][1];
        parents[child].push_back(parent);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(VIS[i]==0)
            recur(parents,i,VIS,ans);
        if(VIS[i]!=2)
        {
            vector<int> temp;
            return temp;
        }
    }
    return ans;
}
};
