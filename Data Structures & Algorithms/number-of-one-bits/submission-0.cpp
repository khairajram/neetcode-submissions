class Solution {
public:
    int hammingWeight(uint32_t n) {
        int no = 0;
        while(n){
            if(n&1)
                no++;
            
            n >>= 1;
        }

        return no;
    }
};
