class Solution {
    void allSum(vector<int>& nums, int target,int i,vector<vector<int>>& ans,vector<int> &vec,int n){
        
        if(target == 0){
            vector<int> temp(vec.begin(), vec.end());
            ans.push_back(temp);
            return;
        }
        
        for(int idx = i;idx < nums.size();idx++){
            if(nums[idx] > target)
                break;
            else if(idx > i && nums[i] == nums[i-1])
                continue;
            
            vec.push_back(nums[idx]);
            allSum(nums,target - nums[idx],idx+1,ans,vec,n);
            vec.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> vec;
        allSum(nums,target,0,ans,vec,n);


        return ans;
    }
};
