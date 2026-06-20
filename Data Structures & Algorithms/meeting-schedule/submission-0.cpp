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
    struct data{
        int end;
        int st;
        int pos;
    };
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<data> inter;
        int pos = 0;
        for(auto i : intervals){
            inter.push_back({i.end,i.start,++pos});
        }
        sort(inter.begin(),inter.end(),
            [](const data& a, const data& b){
            return a.end < b.end;
        });

        for(int i=1;i<inter.size();i++){
            if(inter[i].st < inter[i-1].end)
                return false;
        }

        return true;
    }
};
