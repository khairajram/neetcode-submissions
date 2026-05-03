class Solution {
    void formDp(string s,string rev,vector<vector<int>> &dp){
        int n = s.size();

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s[i] == rev[j])
                    dp[i+1][j+1] = 1 + dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string rev = s;
        reverse(rev.begin(),rev.end());
        formDp(s,rev,dp);

        int i = n,j = n;
        string ans;

        while(i > 0 && j > 0){
            if(s[i-1] == rev[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }else{
                if(dp[i][j] == dp[i][j-1])
                    j--;
                else
                    i--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
