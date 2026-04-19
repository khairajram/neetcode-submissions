class Solution {
    void paren(int open,int close,vector<string> &ans,string &st){
        if(open == 0 && close == 0){
            ans.push_back(st);
            return;
        }

        if(open){
            st += '(';
            paren(open-1,close,ans,st);
            st.erase(st.size()-1,st.size()-1);
        }

        if(open < close){
            st += ')';
            paren(open,close-1,ans,st);
            st.erase(st.size()-1,st.size()-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;
        paren(n,n,ans,st);
        return ans;
    }
};
