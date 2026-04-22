class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int no = 0;
        for(auto i : nums)
            no ^= i;

        return no;
    }
};
