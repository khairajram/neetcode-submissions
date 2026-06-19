class CountSquares {
    unordered_map<int,unordered_map<int,int>> mpx;
    unordered_map<int,unordered_map<int,int>> mpy;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mpx[x][y]++;
        mpy[y][x]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        auto yset = mpx[x];
        auto xset = mpy[y];

        int cnt = 0;

        for(auto ys : yset){
            for(auto xs : xset){
                if(ys.first >= y && xs.first <= x && abs(ys.first - y) == abs(xs.first - x) && mpx[xs.first].find(ys.first) != mpx[xs.first].end())
                    cnt += ys.second*xs.second;
                else if(ys.first <= y && xs.first >= x && abs(ys.first - y) == abs(xs.first - x) && mpx[xs.first].find(ys.first) != mpx[xs.first].end())
                    cnt += ys.second*xs.second;
            }
        }

        return cnt;
    }
};
