class Solution {
public:
    int climbStairs(int n) {
        if(n < 1)
            return 0;
        else if(n == 1 || n == 0 || n == 2)
            return n;
            
        return climbStairs(n-1) + climbStairs(n - 2);
    }
};
