class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int count=0;
        for(int i=0;i<intervals.size();)
        {
            vector<int> temp;
            if(count==0)
            {
                if(intervals[i][0]<=newInterval[0])
                {
                    temp=intervals[i];
                    i++;
                }
                else
                {
                    count=1;
                    temp=newInterval;
                }
            }
            else
            {
                temp=intervals[i];
                i++;
            }
            if(ans.size()==0)
                ans.push_back(temp);
            else
            {
                if(ans[ans.size()-1][1]>=temp[0])
                    ans[ans.size()-1][1]=max(ans[ans.size()-1][1],temp[1]);
                else
                    ans.push_back(temp);
            }
        }
        if(count==0)
        {
            if(ans.size()==0)
                ans.push_back(newInterval);
            else
            {
                vector<int> temp=newInterval;
                if(ans[ans.size()-1][1]>=temp[0])
                    ans[ans.size()-1][1]=max(ans[ans.size()-1][1],temp[1]);
                else
                    ans.push_back(temp);
            }
        }
        return ans;
    }
};
