class Solution {
public:
    void dfs(vector<vector<int>>& tree,int node,vector<int>& VIS) {
        VIS[node]=1;
        for(int i=0;i<tree[node].size();i++)
        {
            if(VIS[tree[node][i]]==0)
                dfs(tree,tree[node][i],VIS);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<int> VIS(n,0);
        int count=0;
        for(int i=0;i<edges.size();i++)
        {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(VIS[i]==0)
            {
                count++;
                dfs(tree,i,VIS);
            }
        }
        return count;
    }
};
