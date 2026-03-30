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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s,e;
        int idx1=0,idx2=0,large=0,count=0;
        for(int i=0;i<intervals.size();i++)
        {
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        while(idx1<s.size() || idx2<e.size())
        {
            int temp1=INT_MAX,temp2=INT_MAX;
            if(idx1<s.size())
                temp1=s[idx1];
            if(idx2<e.size())
                temp2=e[idx2];
            if(temp1<temp2)
            {
                count++;
                idx1++;
            }
            else
            {
                count--;
                idx2++;
            }
            large=max(large,count);
        }
        return large;
    }
};
