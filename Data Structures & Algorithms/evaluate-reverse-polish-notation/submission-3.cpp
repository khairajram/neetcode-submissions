class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        st.push(tokens[0]);
        int n = tokens.size();
        int i = 1;
        while(i < n){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int sec = stoi(st.top());
                st.pop();
                int first = stoi(st.top());
                st.pop();

                if(tokens[i] == "+")
                    st.push(to_string(first + sec));
                else if(tokens[i] == "-")
                    st.push(to_string(first - sec));
                else if(tokens[i] == "*")
                    st.push(to_string(first * sec));
                else if(tokens[i] == "/"){
                    if(sec == 0)
                        st.push(to_string(0));
                    else
                        st.push(to_string(first / sec));
                }

            }else
                st.push(tokens[i]);

            i++;
        }

        return stoi(st.top());
    }
};
