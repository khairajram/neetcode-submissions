class Solution {
    int dfs(vector<vector<int>>& grid,int n,int m,int i,int j){
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        else if(grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        int top = dfs(grid,n,m,i-1,j);
        int bott = dfs(grid,n,m,i+1,j);
        int left = dfs(grid,n,m,i,j-1);
        int right = dfs(grid,n,m,i,j+1);

        return 1 + top + bott + left + right;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    area = max(area,dfs(grid,n,m,i,j));
            }
        }

        return area;
    }
};
