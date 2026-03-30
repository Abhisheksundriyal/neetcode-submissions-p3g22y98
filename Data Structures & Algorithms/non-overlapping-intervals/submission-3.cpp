class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++) {
            if(ans.size()==0 || ans[ans.size()-1][1]<=intervals[i][0])
                ans.push_back(intervals[i]);
            else {
                if(ans[ans.size()-1][1]>intervals[i][1])
                    ans[ans.size()-1]=intervals[i];
                count++;
            }
        }
        return count;
    }
};
