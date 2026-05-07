class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int> st = {0,0,0};

        for(auto i : triplets){
            if(i[0] > t[0] || i[0] > t[0] || i[0] > t[0])
                continue;
            
            st[0] = max(st[0],i[0]);
            st[2] = max(st[2],i[2]);
            st[1] = max(st[1],i[1]);
        }

        return st == t;
    }
};
