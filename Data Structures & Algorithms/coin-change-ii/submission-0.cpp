class Solution {
    int solve(int amount, vector<int>& coins,int i,vector<vector<int>> &dp){
        if(amount == 0)
            return 1;
        else if(i < 0)
            return 0;
        else if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = 0;
        if(amount >= coins[i])
            take = solve(amount - coins[i],coins,i,dp);

        return dp[i][amount] = take + solve(amount,coins,i-1,dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));
        return solve(amount,coins,coins.size() - 1,dp);
    }
};
