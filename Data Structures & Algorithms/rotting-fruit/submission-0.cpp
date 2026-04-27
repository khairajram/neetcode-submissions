class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int f = 0;

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1)
                    f++;
            }
        }

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int time = 0;

        while(!q.empty() && f > 0){
            
            
            int s = q.size();

            for(int p=0;p<s;p++){
                auto [i, j] = q.front();
                q.pop();
                for(auto [dx, dy] : dir){
                    int ni = i + dx;
                    int nj = j + dy;

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m 
                    && grid[ni][nj] == 1){
                        
                        grid[ni][nj] = 2;
                        f--;
                        q.push({ni, nj});
                    }
                }
            }

            time++;
        }

        if(f != 0)
            return -1;

        return time;
    }
};


