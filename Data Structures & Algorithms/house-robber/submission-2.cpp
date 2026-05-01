class Solution {
    int solve(int n,vector<int>& dp,vector<int>& cost){
        if(n < 0)
            return 0;
        else if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = max(solve(n-1,dp,cost) ,cost[n] + solve(n - 2,dp,cost));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];  
        dp[1] = nums[1];

        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],nums[i] + dp[i-2]);
        }  

        return max(dp[n-1],dp[n-2]);
    }
};
