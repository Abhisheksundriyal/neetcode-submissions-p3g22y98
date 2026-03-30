class Solution {
public:
    bool dfs(unordered_map<char,vector<char>>& graph,unordered_map<char,int>& VIS,char node,string& ans) {
    // cout<<"node: "<<node<<"\n";
    VIS[node]=1;
    for(int i=0;i<graph[node].size();i++)
    {
        char next=graph[node][i];
        if(VIS[next]==0)
        {
            if(!dfs(graph,VIS,next,ans))
                return false;
        }
        else if(VIS[next]==1)
            return false;
    }
    VIS[node]=2;
    ans.push_back(node);
    return true;
}

string foreignDictionary(vector<string>& words) {
    string ans;
    unordered_map<char,vector<char>> graph;
    unordered_map<char,int> VIS;
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            vector<char> temp;
            graph[words[i][j]]=temp;
            VIS[words[i][j]]=0;
        }
    }
    for(int i=0;i<words.size()-1;i++)
    {
        string w1=words[i],w2=words[i+1];
        int count=0,len=min(w1.length(),w2.length());
        for(int j=0;j<len;j++)
        {
            if(w1[j]!=w2[j])
            {
                count++;
                graph[w1[j]].push_back(w2[j]);
                break;
            }
        }
        if(count==0 && w1.length()>w2.length())
            return ans;
    }

    for(auto itr=graph.begin();itr!=graph.end();++itr)
    {
        char ch=(*itr).first;
        // cout<<ch<<" : ";
        // for(int i=0;i<graph[ch].size();i++)
        //     cout<<graph[ch][i]<<" ";
        // cout<<"\n";
        if(VIS[ch]==0)
        {
            if(!dfs(graph,VIS,ch,ans))
            {
                // cout<<"helo world\n";
                return "";
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
};
