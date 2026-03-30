class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,int> myMap;
        vector<int> ans;
        for(int i=0;i<intervals.size();i++)
        {
            int l=intervals[i][0],r=intervals[i][1];
            for(int j=l;j<=r;j++)
            {
                if(myMap[j]==0)
                    myMap[j]=(r-l+1);
                else
                    myMap[j]=min(myMap[j],(r-l+1));
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            if(myMap[queries[i]]==0)
                ans.push_back(-1);
            else
                ans.push_back(myMap[queries[i]]);
        }
        return ans;
    }
};
