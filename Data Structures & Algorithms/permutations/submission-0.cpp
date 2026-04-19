class Solution {
    void permu(vector<int> &nums,int i,vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i+1;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permu(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }

        permu(nums,i+1,ans);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permu(nums,0,ans);
        return ans;
    }
};
