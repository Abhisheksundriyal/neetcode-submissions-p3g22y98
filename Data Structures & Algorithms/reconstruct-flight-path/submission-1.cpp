class Solution {
public:
    bool dfs(unordered_map<string,multiset<string>>& myMap,string node,vector<string>& ans,int total) {
    if(ans.size()==total+1)
        return true;
    multiset<string> V=myMap[node];
    for(auto itr=V.begin();itr!=V.end();++itr)
    {
        string next=(*itr);
        auto it=myMap[node].find(next);
        myMap[node].erase(it);
        ans.push_back(next);
        if(dfs(myMap,next,ans,total))
            return true;
        else
        {
            ans.pop_back();
            myMap[node].insert(next);
        }
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    int removed=0,total=tickets.size();
    vector<string> ans;
    unordered_map<string,multiset<string>> myMap;
    for(int i=0;i<tickets.size();i++)
        myMap[tickets[i][0]].insert(tickets[i][1]);
    ans.push_back("JFK");
    dfs(myMap,"JFK",ans,total);
    return ans;
}
};
