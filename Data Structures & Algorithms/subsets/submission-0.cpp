class Solution {
    void allsubset(vector<int>& nums,vector<int> vec,vector<vector<int>> &ans,int i,int n){
        if(i == n){
            ans.push_back(vec);
            return;
        }

        allsubset(nums,vec,ans,i+1,n);
        vec.push_back(nums[i]);
        allsubset(nums,vec,ans,i+1,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        allsubset(nums,{},ans,0,n);

        return ans;
    }
};
