class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        int i = 0;
        
        while(i < n){
            if(newInterval[0] <= intervals[i][0]){
                int st = newInterval[0];
                int end;
                if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                    end = intervals[i][1];
                    ans.push_back({st,end});
                    i++;
                    break;
                }else if(newInterval[1] < intervals[i][0]){
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    i++;
                    break;
                }else if(newInterval[1] > intervals[i][1]){
                   ans.push_back(newInterval);
                   i++;
                   break;
                }
            }
            else if(newInterval[0] > intervals[i][0] && newInterval[0] <= intervals[i][1]){
                int st = intervals[i][0];
                int end;
                if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                    end = intervals[i][1];
                    ans.push_back({st,end});
                    i++;
                    break;
                }else{
                    end = newInterval[1];
                    ans.push_back({st,end});
                    i++;
                    break;
                }
            }
            else{
                ans.push_back(intervals[i]);
                i++;
            }
        }

        while(i < n){
            if(ans[ans.size() - 1][1] > intervals[i][0])
                ans[ans.size() - 1][1] = intervals[i][1];
            else
                ans.push_back(intervals[i]);
            
            i++;
        }

        return ans;
    }
};
