class Solution {
    bool jump(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i == n - 1)
            return true;
        else if(i == n || nums[i] == 0)
            return false;
        else if(dp[i] != -1)
            return dp[i] = true;

        for(int j=1;j<=nums[i];j++)
            if(jump(nums,i+j,n,dp))
                return dp[i] = true;
            
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return jump(nums,0,nums.size(),dp);
    }
};
