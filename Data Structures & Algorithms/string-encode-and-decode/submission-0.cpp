class Solution {
public:

    string encode(vector<string>& strs) {
        string st;

        for(auto s : strs){
            st += to_string(s.size());
            st += "#";
            st += s;
        }

        return st;
    }


    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string> ans;

        while(i < n){
            int len = 0;
            
            while(i < n && s[i] >= '0' && s[i] <= '9'){
                len = len*10 + (s[i] - '0');
                i++;
            }
            i++;
            if(len > 0){
                string st = s.substr(i,len);
                ans.push_back(st);
            }else
                ans.push_back("");
            
            i += len;
        }

        return ans;
    }
};
