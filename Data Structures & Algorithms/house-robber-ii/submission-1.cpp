class Solution {
    int solve(int n,vector<int>& dp,vector<int>& cost,int st){
        if(n < st)
            return 0;
        else if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = max(solve(n-1,dp,cost,st) ,cost[n] + solve(n - 2,dp,cost,st));
    }
public:
    int rob(vector<int>& cost) {
        int n = cost.size();
        if(n == 1)
            return cost[0];
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);

        return max(
            solve(n-2,dp,cost,0),
            solve(n-1,dp2,cost,1)
        );
    }
};