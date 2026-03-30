class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
    int x=-1;
    for(int i=0;i<intervals.size();)
    {
        vector<int> temp;
        if(x==1)
        {
            temp=intervals[i];
            i++;
        }
        else
        {
            if(intervals[i][0]<newInterval[0])
            {
                temp=intervals[i];
                i++;
            }
            else
            {
                temp=newInterval;
                x=1;
            }
        }
        if(ans.size()==0 || ans[ans.size()-1][1]<temp[0])
            ans.push_back(temp);
        else
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],temp[1]);
    }
    if(x==-1)
    {
        vector<int> temp=newInterval;
        if(ans.size()==0 || ans[ans.size()-1][1]<temp[0])
            ans.push_back(temp);
        else
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],temp[1]);
    }
    return ans;
    }
};
