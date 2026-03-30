class Solution {
public:
    int n;
vector<int> parent;
vector<int> size;

void init(int num) {
    n=num;
    for(int i=0;i<=n;i++)
    {
        parent.push_back(0);
        size.push_back(0);
    }
}

void addNode(int node) {
    parent[node]=node;
    size[node]=1;
}

int findParent(int node) { // path compression
    if(parent[node]==node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionBySize(int node1,int node2) {
    int a=findParent(node1),b=findParent(node2);
    if(a!=b)
    {
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int N=edges.size();
    vector<int> ans;
    init(N);
    for(int i=1;i<=N;i++)
        addNode(i);
    for(int i=0;i<N;i++)
    {
        int a=edges[i][0],b=edges[i][1];
        if(findParent(a)==findParent(b))
            ans=edges[i];
        else
            unionBySize(a,b);
    }
    return ans;
}
};
