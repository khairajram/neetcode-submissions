class Solution {
    bool solve(string s, string p,int i,int j,vector<vector<int>> &dp){
        if(i == s.size() && j == p.size())
            return true;
        else if(i >= s.size() || j >= p.size())
            return false;
        else if(dp[i][j] != -1)
            return dp[i][j];

        bool take = false;

        if(s[i] == p[j] || '.' == p[j])
            take = solve(s,p,i+1,j+1,dp);
        else if(s[i] != p[j] && p[j] != '*')
            return dp[i][j] = false;
        else if('*' == p[j])
            take = solve(s,p,i+1,j,dp);

        return dp[i][j] =  take || solve(s,p,i+1,j+1,dp);
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,p,0,0,dp);
    }
};
