class Solution {
public:

    static const int N=1000;

    vector<int> p;
vector<int> SIZE;

Solution() : p(N, 0), SIZE(N, 0) {}

void addNode(int node) {
    SIZE[node]=1;
    p[node]=node;
}

int parent(int node) {
    if(p[node]!=node)
        p[node]=parent(p[node]);
    return p[node];
}

void unionBySize(int a,int b) {
    a=parent(a);
    b=parent(b);
    if(a!=b)
    {
        if(SIZE[a]<SIZE[b])
            swap(a,b);
        p[b]=a;
        SIZE[a]+=SIZE[b];
    }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> cnt(edges.size()+1,0),ans;
    for(int i=1;i<=edges.size();i++)
        addNode(i);
    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0],b=edges[i][1];
        if(parent(a)==parent(b))
            ans=edges[i];
        unionBySize(a,b);
    }
    return ans;
}
};
