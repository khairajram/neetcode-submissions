class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.size();

        vector<int> mp(256,-1);

        while(r < n){
            if(mp[s[r]] == -1){
                ans = max(ans,r-l+1);
                mp[s[r]] = r;
            }else{
                int i = 0;
                int j = mp[s[r]];
                l = mp[s[r]] + 1;

                while(i <= j)
                    mp[i] = -1;
                
                mp[s[r]] = r;
                ans = max(ans,r-l+1);
            }
            r++;
        }

        return ans;
    }
};
