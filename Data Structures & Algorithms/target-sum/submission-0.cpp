class Solution {
    int canpart(vector<int>& nums,int i,int target){
        if(i < 0)
            return target == 0;

        int add = canpart(nums,i-1,target + nums[i]);
        int sub = canpart(nums,i-1,target + (-1) * nums[i]);

        return add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return canpart(nums,n-1,target);
    }
};
