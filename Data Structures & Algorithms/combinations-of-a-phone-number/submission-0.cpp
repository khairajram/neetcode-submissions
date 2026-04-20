class Solution {
    void solve(string digits,vector<string> &mp,vector<string> &ans,string st,int d){
        if(d == digits.size()){
            if(st.size())
                ans.push_back(st);
            return;
        }

        int n = mp[digits[d]-'0'].size();

        for(int i=0;i<n;i++){
            st += mp[digits[d] - '0'][i];
            solve(digits,mp,ans,st,d+1);
            st.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string st;
        solve(digits,mp,ans,st,0);

        return ans;
    }
};
