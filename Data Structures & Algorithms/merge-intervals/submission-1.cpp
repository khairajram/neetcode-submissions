class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int n = intervals.size();
        int i = 0;

        sort(intervals.begin(),intervals.end());

        while(i < n){
            int st = intervals[i][0];
            int end = intervals[i][1];

            i++;

            while(i < n && end >= intervals[i][0])
                end = max(end,intervals[i++][1]);

            ans.push_back({st,end}); 
        }

        return ans;
    }
};
