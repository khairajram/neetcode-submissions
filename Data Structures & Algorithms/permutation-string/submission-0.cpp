#include <string>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int n1 = s1.size();
        int n2 = s2.size();

        int i = 0;
        int j = n1 - 1;

        while(j < n2){
            string st = s2.substr(i,n1);
            sort(st.begin(),st.end());
            if(st == s1)
                return true;
            
            i++;
            j++;
        }

        return false;
    }
};
