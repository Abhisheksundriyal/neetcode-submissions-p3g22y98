class Solution {
public:
    void dfs(vector<vector<int>>& tree,int node,int prev,
                vector<int>& VIS,bool& ans,int& count) {
        count++;
        VIS[node]=1;
        for(int i=0;i<tree[node].size();i++)
        {
            int newNode=tree[node][i];
            if(newNode!=prev)
            {
                if(VIS[newNode]==1)
                    ans=false;
                else
                    dfs(tree,newNode,node,VIS,ans,count);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        int count=0;
        vector<int> VIS(n,0);
        bool ans=true;
        for(int i=0;i<edges.size();i++)
        {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(tree,0,-1,VIS,ans,count);
        return (count==n && ans);
    }
};
