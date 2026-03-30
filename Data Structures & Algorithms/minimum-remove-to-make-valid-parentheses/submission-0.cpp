class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> mySet;
        string ans;
        int n=s.size();
        stack<pair<char,int>> myStac;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(s[i]!='(' && s[i]!=')')
                continue;
            if(myStac.empty())
            {
                if(s[i]=='(')
                    myStac.push({s[i],i});
                else
                    mySet.insert(i);
            }
            else
            {
                if(s[i]==')')
                {
                    if(myStac.top().first=='(')
                        myStac.pop();
                    else
                        mySet.insert(i);
                }
                else
                    myStac.push({s[i],i});
            }
        }
        while(!myStac.empty())
        {
            mySet.insert(myStac.top().second);
            myStac.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(mySet.find(i)==mySet.end())
                ans.push_back(s[i]);
        }
        return ans;
    }
};
