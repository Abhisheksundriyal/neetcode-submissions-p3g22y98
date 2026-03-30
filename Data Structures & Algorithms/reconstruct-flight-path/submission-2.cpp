class Solution {
public:
    void dfs(unordered_map<string,multiset<string>>& myMap,string node,vector<string>& ans) {
    while(!myMap[node].empty())
    {
        auto itr=myMap[node].begin();
        string next=(*itr);
        myMap[node].erase(itr);
        dfs(myMap,next,ans);
    }
    ans.push_back(node);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    unordered_map<string,multiset<string>> myMap;
    for(int i=0;i<tickets.size();i++)
        myMap[tickets[i][0]].insert(tickets[i][1]);
    dfs(myMap,"JFK",ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
};
