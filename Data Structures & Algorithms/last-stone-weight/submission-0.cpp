class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto st : stones)
            pq.push(st);

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y)
                continue;
            pq.push((x < y) ? (y - x) : (x - y));
        }

        if(pq.size() == 1)
            return pq.top();

        return 0;
    }
};
