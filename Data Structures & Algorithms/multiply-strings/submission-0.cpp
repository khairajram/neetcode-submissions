class Solution {
    string addStrings(string num1, string num2) {
        string ans;

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {

            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;

            int sum = x + y + carry;

            ans += ('0' + sum % 10);
            carry = sum / 10;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        int i = n - 1;
        int p = 0;
        string ans = "";

        while(i >= 0){
            string st = "";
            int j = m - 1;
            int x = num1[i--] - '0';
            int c = 0;
            while(j >= 0){
                int y = num2[j--] - '0';
                int pro = x*y + c;
                st += ('0' + pro%10);
                c = pro/10;
            }

            if(c > 0)
                st += to_string(c);

            reverse(st.begin(),st.end());
            
            st += string(p++,'0');

            ans = addStrings(st,ans);
        }

        return ans;
    }
};
