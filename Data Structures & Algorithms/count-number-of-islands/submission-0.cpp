class Solution {
    vector<int> dir1 = {-1,0,1,0};
    vector<int> dir2 = {0,1,0,-1};

    bool isValid(int n,int m,int i,int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void BFS(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j,int n,int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            i = front.first;
            j = front.second;
            for(int k=0;k<4;k++){
                int ni = i + dir1[k];
                int nj = j + dir2[k];
                if(isValid(n,m,ni,nj) && !vis[ni][nj] && grid[ni][nj] == '1'){
                    q.push({ni,nj});
                    vis[ni][nj] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int isLand = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    BFS(grid,vis,i,j,n,m);
                    isLand++;
                }
            }
        }
        
        return isLand;
    }
};
