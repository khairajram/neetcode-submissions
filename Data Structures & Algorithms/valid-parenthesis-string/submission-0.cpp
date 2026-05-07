class Solution {
    bool solve(string s,int o,int c,int i){
        if(i >= s.size())
            return o == c;
        else if(c > o)
            return false;

        bool ss = false;

        if(s[i] == '('){
            ss |= solve(s,o+1,c,i+1);
        }else if(s[i] == ')'){
            ss |= solve(s,o,c+1,i+1);
        }else{
            ss |= solve(s,o+1,c,i+1);
            ss |= solve(s,o,c+1,i+1);
            ss |= solve(s,o,c,i+1);
        }

        return ss;
    }
public:
    bool checkValidString(string s) {    
        return solve(s,0,0,0);
    }
};
