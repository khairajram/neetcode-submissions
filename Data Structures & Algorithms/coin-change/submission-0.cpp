class Solution {
    int change(vector<int> &coins, int amt, int i, vector<vector<int>> &dp){
        if(amt == 0) return 0;
        if(i < 0) return 1e9;

        if(dp[i][amt] != -1)
            return dp[i][amt];

        int take = 1e9;
        if(amt >= coins[i])
            take = 1 + change(coins, amt - coins[i], i, dp);

        int notTake = change(coins, amt, i-1, dp);

        return dp[i][amt] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));

        int ans = change(coins, amt, n-1, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};