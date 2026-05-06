class Solution {
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int solve(vector<vector<int>>& mat,vector<vector<bool>> &vis,vector<vector<int>> &dp,int i,int j){

        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 1;

        vis[i][j] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(auto t : dir){
            int x = i + t.first;
            int y = j + t.second;

            if(x >= 0 && y >= 0 && x < n && y < m && mat[i][j] < mat[x][y])
                dp[i][j] = max(dp[i][j],1 + solve(mat,vis,dp,x,y));
            
        }

        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    ans = max(ans,solve(matrix,vis,dp,i,j));
        
        return ans;
    }
};
