class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ans = 0;
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i])
                continue;
            else if(nums[i-1] + 1 == nums[i]){
                cnt++;
                ans = max(ans,cnt);
            }else{
                cnt = 1;
            }
        }

        return ans;
    }
};
