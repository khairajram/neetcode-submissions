class Solution {
    int solve(string s,int i,vector<int> &dp){
        if(i >= s.size() - 1)
            return 1;
        else if(i == s.size() - 1)
            return 1;
        else if(dp[i] != -1)
            return -1;

        if(i + 1 < s.size() && s[i+1] == '0')
            return dp[i] = solve(s,i+2,dp);

        return dp[i] = solve(s,i+1,dp) + solve(s,i+2,dp);
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};
