class Solution {
public:
    bool isHappy(int n) {
    unordered_set<int> st;

    while (n > 1) {
        if (st.count(n)) return false;

        st.insert(n);

        int sum = 0;
        int temp = n;  // safer

        while (temp) {
            int d = temp % 10;
            sum += d * d;
            temp /= 10;
        }

        n = sum;
    }

    return true;
}
};
