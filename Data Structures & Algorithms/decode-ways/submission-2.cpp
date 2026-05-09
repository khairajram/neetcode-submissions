class Solution {
    int solve(string s,int i,vector<int> &dp){
        if(i == s.size())
            return 1;
        else if(s[i] == '0')
            return 0;
        else if(dp[i] != -1)
            return dp[i];

        int ways = solve(s,i+1,dp);

        if(i + 1 < s.size()){
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26)
                ways += solve(s, i + 2, dp);
        }

        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};
