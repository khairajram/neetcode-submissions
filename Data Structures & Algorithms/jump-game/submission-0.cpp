class Solution {
    bool jump(vector<int> &nums,int i,int n){
        if(i == n - 1)
            return true;
        else if(i == n || nums[i] == 0)
            return false;

        for(int j=1;j<=nums[i];j++)
            if(jump(nums,i+j,n))
                return true;
            
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return jump(nums,0,nums.size());
    }
};
