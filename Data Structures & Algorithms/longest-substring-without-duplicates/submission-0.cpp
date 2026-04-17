class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.size();

        vector<int> mp(26,-1);

        while(r < n){
            if(mp[s[r] - 'a'] == -1){
                ans = max(ans,r-l+1);
                mp[s[r] - 'a'] = r;
            }else{
                int i = 0;
                int j = mp[s[r] - 'a'];
                l = mp[s[r] - 'a'] + 1;

                while(i <= j)
                    mp[i] = -1;
                
                mp[s[r] - 'a'] = r;
                ans = max(ans,r-l+1);
            }
            r++;
        }

        return ans;
    }
};
