class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int coin = prices[0];
        int i = 1;
        int ans = 0;
        while(i < prices.size()){
            if(prices[i] < coin)
                coin = prices[i];
            else
                ans = max(ans,prices[i] - coin);
            
            i++;
        }

        return ans;
    }

};
