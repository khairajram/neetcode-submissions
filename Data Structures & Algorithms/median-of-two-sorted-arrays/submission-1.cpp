class Solution {
    double binsch(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)
            return binsch(nums2,nums1);

        int st = 0;
        int end = n1;
        int tar = (n1 + n2 + 1)/2;

        while(st <= end){
            int mid1 = st + (end - st)/2;
            int mid2 = tar - mid1;

            int l1 = (mid1 - 1 >= 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                double ans = ((n1 + n2)%2 == 0) ? (double)(max(l1,l2) + min(r1,r2))/2 : max(l1,l2);
                return ans;
            }
            else if(l1 > r2)
                end = mid1 - 1;
            else
                st = mid1 + 1;
        }

        return 1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return binsch(nums1,nums2);
    }
};