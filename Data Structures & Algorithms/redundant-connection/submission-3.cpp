class Solution {
public:
    unordered_map<int,int> SIZE,PARENT;

    void make(int node) {
        PARENT[node]=node;
        SIZE[node]=1;
    }

    int findParent(int node) {
        if(node==PARENT[node])
            return node;
        return PARENT[node]=findParent(PARENT[node]);
    }

    void makeUnion(int a,int b) {
        a=findParent(a);
        b=findParent(b);
        if(a!=b) {
            if(SIZE[a]<SIZE[b])
                swap(a,b);
            PARENT[b]=a;
            SIZE[a]+=SIZE[b];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        for(int i=0;i<edges.size();i++) {
            make(edges[i][0]);
            make(edges[i][1]);
        }
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0],b=edges[i][1];
            if(findParent(a)!=findParent(b))
                makeUnion(a,b);
            else
                ans=edges[i];
        }
        return ans;
    }
};
