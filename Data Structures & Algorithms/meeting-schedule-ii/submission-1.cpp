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
        int count=0;
        multiset<pair<int,int>> mySet;
        for(int i=0;i<intervals.size();i++)
            mySet.insert({intervals[i].start,intervals[i].end});
        
        while(!mySet.empty())
        {
            count++;
            auto itr=mySet.begin();
            pair<int,int> p={(*itr).second,(*itr).second};
            mySet.erase(itr);
            itr=mySet.lower_bound(p);
            while(itr!=mySet.end())
            {
                pair<int,int> P={(*itr).second,(*itr).second};
                mySet.erase(itr);
                itr=mySet.lower_bound(P);
            }
        }
        return count;
    }
};
