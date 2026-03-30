class Solution {
public:
    void dfs(vector<vector<int>>& tree,vector<int>& VIS,int node,
            vector<int>& ans,bool& exist) {
        VIS[node]=1;
        for(int i=0;i<tree[node].size();i++)
        {
            if(VIS[tree[node][i]]==0)
                dfs(tree,VIS,tree[node][i],ans,exist);
            else if(VIS[tree[node][i]]==1)
                exist=false;
        }
        VIS[node]=2;
        ans.push_back(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> VIS(numCourses,0),ans;
        bool exist=true;
        vector<vector<int>> tree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0],b=prerequisites[i][1];
            tree[a].push_back(b);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(VIS[i]==0)
                dfs(tree,VIS,i,ans,exist);
        }
        if(!exist)
            return {};
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
