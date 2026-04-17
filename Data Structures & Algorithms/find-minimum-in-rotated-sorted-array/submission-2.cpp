class Solution {
    int elems(vector<int> &nums){
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while(st < end){
            int mid = st + (end - st)/2;

            if(nums[mid] > nums[end])
                st = mid + 1;
            else
                end = mid;
        }

        return nums[st];
    }
public:
    int findMin(vector<int> &nums) {
        if(nums[0] <= nums[nums.size() - 1])
            return nums[0];

        return elems(nums);
    }
};
