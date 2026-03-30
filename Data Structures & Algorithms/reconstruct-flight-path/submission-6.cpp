class Solution {
public:
    unordered_map<string,multiset<string>> graph;
    vector<string> ans;
    void dfs(string node) {
        while(!graph[node].empty())
        {
            auto itr=graph[node].begin();
            string newNode=(*itr);
            graph[node].erase(itr);
            dfs(newNode);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++)
        {
            string from=tickets[i][0],to=tickets[i][1];
            graph[from].insert(to);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
