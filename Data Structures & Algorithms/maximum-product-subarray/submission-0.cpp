class Solution {
    int pro(vector<int>& nums,int i,int p){
        if(i == nums.size())
            return p;
        
        return max(pro(nums,i+1,nums[i]*p),pro(nums,i+1,nums[i]));
    }
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;

        int pref = 1;
        int sufi = 1;

        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            if(pref == 0)
                pref = 1;
            if(sufi == 0)
                sufi = 1;

            pref *= nums[i];
            sufi *= nums[n - 1 - i];

            maxi = max({maxi,pref,sufi});
        }

        return maxi;
    }
};
