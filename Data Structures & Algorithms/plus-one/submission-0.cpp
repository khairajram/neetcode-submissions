class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 1;
        int n = digits.size();

        for(int i=n-1;i>=0;i--){
            sum = digits[i] + sum;
            digits[i] = sum % 10;
            sum /= 10;
        }

        if(sum > 0)
             digits.insert(digits.begin(), sum); 

        return digits;
    }
};
