class Solution {
    int elems(vector<int> &nums){
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[0] < nums[mid] && mid + 1 < n && nums[mid] > nums[mid + 1])
                return nums[mid+1];
            else if(nums[0] > nums[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }

        return -1;
    }
public:
    int findMin(vector<int> &nums) {
        if(nums[0] <= nums[nums.size() - 1])
            return nums[0];

        return elems(nums);
    }
};
