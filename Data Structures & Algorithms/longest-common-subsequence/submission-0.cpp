class Solution {
    int formDp(string s,string rev,vector<vector<int>> &dp){
        int ans = 0;
        int n1 = s.size();
        int n2 = rev.size();

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(s[i] == rev[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                    ans = max(dp[i+1][j+1],ans);
                }
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }

        return ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));


        return formDp(text1,text2,dp);
    }
};
