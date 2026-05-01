class Solution {
    int solve(int n,vector<int>& dp,vector<int>& cost){
        if(n == 1 || n == 0)
            return cost[n];
        else if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = cost[n] + min(solve(n-1,dp,cost) , solve(n - 2,dp,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        

        return min(
            solve(cost.size()-1,dp,cost),
            solve(cost.size()-2,dp,cost)
        );
    }
};
