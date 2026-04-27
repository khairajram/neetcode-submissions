class Solution {
    void travers(vector<vector<int>>& grid,int i,int j,int dist,vector<vector<bool>> &vis){
        if(i < 0 || j < 0|| i >= grid.size() || j >= grid[0].size())
            return;
        else if(grid[i][j] == -1 || vis[i][j])
            return;

        vis[i][j] = 1;
        
        grid[i][j] = min(grid[i][j],dist);
        travers(grid,i-1,j,dist+1,vis);
        travers(grid,i+1,j,dist+1,vis);
        travers(grid,i,j-1,dist+1,vis);
        travers(grid,i,j+1,dist+1,vis);
        vis[i][j] = 0;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0)
                    travers(grid,i,j,0,vis);
            }
        }
    }
};
