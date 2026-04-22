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

        return st;
    }
    int binSch(vector<int> &nums,int st,int end,int target){

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid - 1;
            else
                st = mid + 1;                
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = elems(nums);
        cout<<st<<endl;
        int ans = binSch(nums,0,st-1,target);
        if(ans == -1)
            ans = binSch(nums,st,n-1,target);

        return ans;
    }
};
