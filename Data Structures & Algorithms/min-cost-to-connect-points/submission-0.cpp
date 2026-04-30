class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0,{points[0][0],points[0][1]}});

        map<pair<int,int>, bool> vis;
        int dist = 0;

        while(!pq.empty()){

            auto top = pq.top();
            int dit = top.first;
            int x = top.second.first;
            int y = top.second.second;

            pq.pop();

            if (vis[{x,y}]) continue;

            vis[{x,y}] = true;

            dist += dit;

            for(auto i : points){
                int nx = i[0];
                int ny = i[1];

                int d = abs(nx - x) + abs(ny - y);

                if(!vis[{nx,ny}])
                    pq.push({d,{nx,ny}});
            }
        }

        return dist;
    }
};
