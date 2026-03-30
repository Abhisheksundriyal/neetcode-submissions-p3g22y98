class Solution {
public:

    void dfs(vector<vector<int>>& graph,vector<int>& VIS,int node) {
        VIS[node]=1;
        for(int i=0;i<graph[node].size();i++)
        {
            if(VIS[graph[node][i]]==0)
                dfs(graph,VIS,graph[node][i]);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> VIS(n,0);
        int count=0;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(VIS[i]==0)
            {
                count++;
                dfs(graph,VIS,i);
            }
        }
        return count;
    }
};
