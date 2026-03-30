class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> myStac;
        vector<int> ans(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!myStac.empty() && myStac.top().first<=temperatures[i])
                myStac.pop();
            int temp=0;
            if(!myStac.empty())
                temp=myStac.top().second-i;
            myStac.push({temperatures[i],i});
            ans[i]=temp;
        }
        return ans;
    }
};
