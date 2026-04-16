class Solution {
    void allSum(vector<int>& nums, int target,int i,vector<vector<int>>& ans,vector<int> &vec,int n){
        if(i >= n)
            return;
        else if(target == 0){
            ans.push_back(vec);
            return;
        }

        if(target >= nums[i]){
            vec.push_back(nums[i]);
            allSum(nums,target - nums[i],i,ans,vec,n);
            vec.pop_back();
        }

        allSum(nums,target,i+1,ans,vec,n);


    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> vec;
        allSum(nums,target,0,ans,vec,n);

        return ans;
    }
};
