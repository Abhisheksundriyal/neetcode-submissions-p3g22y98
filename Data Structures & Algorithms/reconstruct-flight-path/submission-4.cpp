class Solution {
public:
    void dfs(string node,unordered_map<string,multiset<string>>& graph,
            vector<string>& ans) {
    while(!graph[node].empty()) {
        auto itr=graph[node].begin();
        string next=(*itr);
        graph[node].erase(itr);
        dfs(next,graph,ans);
    }
    ans.push_back(node);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string,multiset<string>> graph;
    vector<string> ans;
    for(int i=0;i<tickets.size();i++)
        graph[tickets[i][0]].insert(tickets[i][1]);
    dfs("JFK",graph,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
};
