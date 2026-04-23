class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>
        > pq;

        for(auto i : points){
            int x = i[0];
            int y = i[1];

            int dist = (x*x + y*y);

            pq.push({dist,{x,y}});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(pq.size() > 0){
            auto t = pq.top();
            pq.pop();

            ans.push_back({t.second.first,t.second.second});
        }

        return ans;
    }
};
