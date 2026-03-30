class Solution {
public:
    void recur(vector<vector<int>>& tree,vector<int>& VIS
                ,int node,bool& ans) {
        VIS[node]=1;
        for(int i=0;i<tree[node].size();i++)
        {
            if(VIS[tree[node][i]]==0)
                recur(tree,VIS,tree[node][i],ans);
            else if(VIS[tree[node][i]]==1)
                ans=false;
        }
        VIS[node]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> tree(numCourses);
        vector<int> VIS(numCourses,0);
        bool ans=true;
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0],b=prerequisites[i][1];
            tree[a].push_back(b);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(VIS[i]==0)
                recur(tree,VIS,i,ans);
        }
        return ans;
    }
};
