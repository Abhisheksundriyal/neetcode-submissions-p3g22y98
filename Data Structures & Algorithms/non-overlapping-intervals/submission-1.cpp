class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,last=-1;
        for(int i=0;i<intervals.size();i++) {
            if(last==-1)
                last=intervals[i][1];
            else
            {
                if(last>intervals[i][0])
                {
                    count++;
                    last=min(last,intervals[i][1]);
                }
                else
                    last=intervals[i][1];
            }
        }
        return count;
    }
};
