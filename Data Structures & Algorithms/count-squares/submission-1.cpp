class CountSquares {
    unordered_map<int,unordered_map<int,int>> mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mp[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int cnt = 0;

        for(auto ys : mp[x]){
            int d = abs(ys.first - y);

            if(d == 0)
                continue;

            // left
            if(mp.find(x - d) != mp.end()){
                if(mp[x-d].find(ys.first) != mp[x-d].end() && mp[x-d].find(y) != mp[x-d].end())
                    cnt += mp[x-d][y] * mp[x-d][ys.first] * mp[x][ys.first];
            }

            // right
            if(mp.find(x + d) != mp.end()){
                if(mp[x+d].find(ys.first) != mp[x+d].end() && mp[x+d].find(y) != mp[x+d].end())
                    cnt += mp[x+d][y] * mp[x+d][ys.first] * mp[x][ys.first];
            }
        }

        return cnt;
    }
};
