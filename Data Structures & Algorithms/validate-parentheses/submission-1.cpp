class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        stack<int> st;

        while(i < n){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            i++;
        }

        if(!st.empty())
            return false;

        return true;
    }
};
