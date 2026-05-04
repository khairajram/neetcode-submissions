class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0,n = s.size();
        char ch;
        int c = k;
        int ans = 0;

        while(r < n){
            if(l == r){
                ch = s[l];
                ans = max(ans,r-l+1);
                r++;
            }else if(ch == s[r]){
                ans = max(ans,r-l+1);
                r++;
            }else if(c > 0){
                c--;
                ans = max(ans,r-l+1);
                r++;
            }else{
                ans = max(ans,r-l);
                c = k;
                l = r;
            }
        }

        return ans;
    }
};
