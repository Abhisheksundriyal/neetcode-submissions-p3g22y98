class Solution {
public:
    void dfs(int node,int prev,vector<vector<int>>& neighbours,
    vector<int>& VIS,bool& ans) {
    VIS[node]=1;
    for(int i=0;i<neighbours[node].size();i++)
    {
        if(VIS[neighbours[node][i]]==0)
            dfs(neighbours[node][i],node,neighbours,VIS,ans);
        else if(neighbours[node][i]!=prev)
            ans=false;
    }
}

bool validTree(int n, vector<vector<int>>& edges) {
    bool ans=true;
    int count=0;
    vector<vector<int>> neighbours(n);
    vector<int> VIS(n,0);
    for(int i=0;i<edges.size();i++)
    {
        neighbours[edges[i][0]].push_back(edges[i][1]);
        neighbours[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<n;i++)
    {
        if(VIS[i]==0)
        {
            if(count==0)
            {
                count=1;
                dfs(i,-1,neighbours,VIS,ans);
            }
            else
                return false;
        }
    }
    return ans;
}
};
