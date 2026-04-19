class Solution {
    void subset(vector<int>& nums,int i,int n,vector<vector<int>> &ans,vector<int>& list){

        ans.push_back(list);

        for(int idx=i;idx<n;idx++){
            if(idx > i && nums[idx] == nums[idx - 1])
                continue;
            list.push_back(nums[idx]);
            subset(nums,idx+1,n,ans,list);
            list.pop_back();
        }


    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> list;
        subset(nums,0,nums.size(),ans,list);
        return ans;
    }
};
