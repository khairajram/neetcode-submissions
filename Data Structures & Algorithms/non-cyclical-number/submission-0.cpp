class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> mp;

        while(n > 1){
            if(mp.find(n) != mp.end())
                return false;

            mp[n] = 1;
            int sum = 0;
            while(n){
                sum += n%10 * n%10;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};
