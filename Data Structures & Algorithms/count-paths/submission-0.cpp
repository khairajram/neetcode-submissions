class Solution {
    int solve(vector<vector<int>> &dp,int i,int j,int n,int m){
        if(i == n - 1 && j == m - 1)
            return 1;
        else if(dp[i][j] != -1)
            return dp[i][j];

        int sum = 0;
        if(i + 1 < n)
            sum += solve(dp,i+1,j,n,m);
        
        if(j + 1 < m)
            sum += solve(dp,i,j+1,n,m);

        return dp[i][j] = sum;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(dp,0,0,m,n);
    }
};
