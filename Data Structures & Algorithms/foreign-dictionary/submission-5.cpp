class Solution {
public:
    void dfs(char node,unordered_map<char,unordered_set<char>>& graph,unordered_map<char,int>& VIS,string& ans,bool& exist) {
        // cout<<"node1: "<<node<<"\n";
        if(!exist)
            return;
        VIS[node]=1;
        unordered_set<char>& V=graph[node];
       for(auto itr=V.begin();itr!=V.end();++itr)
        {
            char newNode=(*itr);
            if(VIS[newNode]==0)
                dfs(newNode,graph,VIS,ans,exist);
            if(VIS[newNode]==1)
                exist=false;
        }
        VIS[node]=2;
        // cout<<"node: "<<node<<"\n";
        ans.push_back(node);
    }

    string foreignDictionary(vector<string>& words) {
        string ans;
        unordered_map<char,unordered_set<char>> graph;
        unordered_map<char,int> VIS;
        bool exist=true;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i][j];j++)
                VIS[words[i][j]]=0;
        }
        for(int i=1;i<words.size();i++) {
            string prev=words[i-1],curr=words[i];
            if(curr==prev)
                continue;
            int count=0;
            for(int j=0;j<min(prev.size(),curr.size());j++) {
                if(prev[j]!=curr[j]) {
                    count=1;
                    // cout<<"u: "<<curr[j]<<" v: "<<prev[j]<<"\n";
                    graph[curr[j]].insert(prev[j]);
                    break;
                }
            }
            if(count==0 && curr.size()<prev.size())
                return {};
        }
        for(auto itr=VIS.begin();itr!=VIS.end();++itr) {
            char node=(*itr).first;
            if(VIS[node]==0)
                dfs(node,graph,VIS,ans,exist);
        }
        if(!exist)
            return {};
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
