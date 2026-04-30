class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto i : times)
            adj[i[0]].push_back({i[1],i[2]});
        
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto [t , src] = pq.top();
            pq.pop();

            for(auto neg : adj[src]){
                if(time[neg.first] > t + neg.second){
                    time[neg.first] = t + neg.second;
                    pq.push({time[neg.first],neg.first});
                }
            }
        }

        int maxi = 0;
        for(int i=1;i<=n;i++)
            maxi = max(maxi,time[i]);

        return maxi == INT_MAX ? -1 : maxi;
    }
};
