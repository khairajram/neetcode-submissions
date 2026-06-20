class Solution {
    struct data{
        int end;
        int st;
        int pos;
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<data> inter;
        int pos = 0;
        for(auto i : intervals){
            inter.push_back({i[1],i[0],++pos});
        }
        int cnt = 0;
        sort(inter.begin(),inter.end(),
            [](const data& a, const data& b){
            return a.end < b.end;
        });

        auto last = inter[0];

        for(int i=1;i<inter.size();i++){
            if(inter[i].st <last.end)
                cnt++;
            else
                last = inter[i];
        }

        return cnt;
    }
};
