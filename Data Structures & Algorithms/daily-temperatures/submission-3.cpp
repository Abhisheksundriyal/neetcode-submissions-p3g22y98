class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> myStac;
        int n=temperatures.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int x=temperatures[i];
            while(!myStac.empty() && temperatures[myStac.top()]<=x)
                myStac.pop();
            if(myStac.empty())
                ans[i]=0;
            else
                ans[i]=myStac.top()-i;
            myStac.push(i);
        }
        return ans;
    }
};
