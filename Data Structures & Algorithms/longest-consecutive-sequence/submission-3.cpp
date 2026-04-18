class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> st;

        for(auto i : nums)
            st.insert(i);

        for(auto i : nums){
            if(st.count(i-1))
                continue;
            int cnt = 1;
            int ele = i+1;
            while(st.count(ele)){
                cnt++;
                ele++;
            }

            ans = max(ans,cnt);
        }

        return ans;
    }
};
