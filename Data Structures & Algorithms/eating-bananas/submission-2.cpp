class Solution {
    bool posi(vector<int>& piles,int k,int h){
        int hr = 0;
        for(auto i : piles){
            if(i%k == 0)
                hr += i/k;
            else{
                hr += i/k;
                hr += 1;
            }
        }

        return hr <= h ? true : false;
    }
    int binSch(vector<int>& piles,int h){
        int st = 1;
        int end = *max_element(piles.begin(),piles.end());
        
        while(st < end){
            int mid = st + (end - st)/2;

            bool isPosi = posi(piles,mid,h);
            if(isPosi)
                end = mid;
            else 
                st = mid + 1;
        }

        return st;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return binSch(piles,h);
    }
};
