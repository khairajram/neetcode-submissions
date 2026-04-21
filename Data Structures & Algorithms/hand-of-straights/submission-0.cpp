class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize != 0)
            return false;
        sort(hand.begin(),hand.end());
        int no = n/groupSize;

        while(no){
            int cnt = groupSize;
            int last = -1;

            for(auto &i : hand){
                if(i == -1)
                    continue;
                if(last == -1 || i - 1 == last){
                    cnt--;
                    last = i;
                    i = -1;
                }

                if(cnt == 0)
                    break;
            }

            if(cnt > 0)
                return false;

            no--;
        }

        return true;
    }
};
