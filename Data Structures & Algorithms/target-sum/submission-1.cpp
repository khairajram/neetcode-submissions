class Solution {

    int canpart(vector<int>& nums,
                int i,
                int target,
                vector<unordered_map<int,int>>& dp) {

        if(i < 0)
            return target == 0;

        if(dp[i].count(target))
            return dp[i][target];

        int add = canpart(nums,
                          i - 1,
                          target - nums[i],
                          dp);

        int sub = canpart(nums,
                          i - 1,
                          target + nums[i],
                          dp);

        return dp[i][target] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<unordered_map<int,int>> dp(n);

        return canpart(nums, n - 1, target, dp);
    }
};