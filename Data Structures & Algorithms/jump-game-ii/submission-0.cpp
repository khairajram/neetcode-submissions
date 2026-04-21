class Solution {
    int jump(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i == n - 1)
            return 0;
        else if(i == n || nums[i] == 0)
            return 1e9;
        else if(dp[i] != -1)
            return dp[i];

        int jp = INT_MAX;

        for(int j=1;j<=nums[i];j++)
            jp = min(jp,1 + jump(nums,i+j,n,dp));
            
        return dp[i] = jp;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return jump(nums,0,nums.size(),dp);
    }
};
