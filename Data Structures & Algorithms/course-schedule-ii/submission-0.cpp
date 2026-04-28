class Solution {
    bool dfs_cycle_detect(vector<vector<int>> &adj,int i,vector<int> &vis,stack<int> &st){
        vis[i] = 1;

        for(auto j : adj[i])
            if(vis[j] == 0 && dfs_cycle_detect(adj,j,vis,st))
                return true;
            else if(vis[j] == 1)
                return true;

        vis[i] = 2;
        st.push(i);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<int> vis(n,0);
        vector<int> ans;
        stack<int> st;
        vector<vector<int>> adj(n);

        for(auto i : preq)
            adj[i[1]].push_back(i[0]);

        for(int i=0;i<n;i++)
            if(vis[i] == 0 && dfs_cycle_detect(adj,i,vis,st))
                return ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
