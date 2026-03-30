class Solution {
public:
    void recur(vector<vector<int>>& tree,vector<int>& VIS,int prev,int node,bool& ans) {
    VIS[node]=1;
    int n=tree[node].size();
    for(int i=0;i<n;i++)
    {
        int next=tree[node][i];
        if(next!=prev)
        {
            if(VIS[next]==1)
            {
                ans=false;
                return;
            }
            else
                recur(tree,VIS,node,next,ans);
        }
    }
}

bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> tree(n);
    vector<int> VIS(n,0);
    int count=0;
    bool ans=true;
    for(int i=0;i<edges.size();i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<n;i++)
    {
        if(VIS[i]==0)
        {
            if(count!=0)
                return false;
            count++;
            recur(tree,VIS,-1,i,ans);
        }
    }
    return ans;
}
};
