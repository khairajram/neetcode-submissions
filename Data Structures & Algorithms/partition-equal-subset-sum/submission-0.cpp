class Solution {
    bool canpart(vector<int>& nums,int i,int target){
        if(target == 0)
            return true;
        else if(i < 0)
            return false;

        bool take  = false;
        if(target >= nums[i])
            take = canpart(nums,i-1,target-nums[i]);

        return take || canpart(nums,i-1,target);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1)
            return false;
        int n = nums.size();
        return canpart(nums,n-1,sum/2);
    }
};
