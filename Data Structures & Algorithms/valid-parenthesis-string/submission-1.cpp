class Solution {
    bool solve(string s,int o,int i,vector<vector<int>> &dp){
        if(i >= s.size())
            return o == 0;
        else if(o < 0)
            return false;
        else if(dp[i][o] != -1)
            return dp[i][o];

        bool ss = false;

        if(s[i] == '('){
            ss |= solve(s,o+1,i+1,dp);
        }else if(s[i] == ')'){
            ss |= solve(s,o-1,i+1,dp);
        }else{
            ss |= solve(s,o+1,i+1,dp);
            ss |= solve(s,o-1,i+1,dp);
            ss |= solve(s,o,i+1,dp);
        }

        return dp[i][o] = ss;
    }
public:
    bool checkValidString(string s) {   
        int n = s.size(); 
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,0,dp);
    }
};
