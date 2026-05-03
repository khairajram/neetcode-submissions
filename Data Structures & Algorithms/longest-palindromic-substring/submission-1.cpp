class Solution {
    pair<int,int> formDp(string s,string rev,vector<vector<int>> &dp){
        int n = s.size();
        int maxi = 0;
        int st = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i] == rev[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                    
                    int len = dp[i+1][j+1];

                    if(maxi < len && ((i - len + 1) == (n - 1 - j))){
                        maxi = len;
                        st = i - len + 1;
                    }
                    
                }
                else
                    dp[i+1][j+1] = 0;
            }
        }

        return {st,maxi};
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        string rev = s;
        reverse(rev.begin(),rev.end());

        auto [st, maxi] = formDp(s, rev, dp);

        return s.substr(st, maxi);
    }
};
