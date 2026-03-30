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
    static bool compare(Interval& p1,Interval& p2) {
        if(p1.start<p2.start)
            return true;
        else if(p1.start==p2.start)
        {
            if(p1.end<p2.end)
                return true;
        }
        return false;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i-1].end>intervals[i].start)
                return false;
        }
        return true;
    }
};
