/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> temp;
        int last=INT_MIN;
        for(int i=0;i<intervals.size();i++) {
            vector<int> t;
            t.push_back(intervals[i].start);
            t.push_back(intervals[i].end);
            temp.push_back(t);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            if(last==INT_MIN)
                last=temp[i][1];
            else
            {
                if(temp[i][0]<last)
                    return false;
                else
                    last=max(last,temp[i][1]);
            }
        }
        return true;
    }
};
