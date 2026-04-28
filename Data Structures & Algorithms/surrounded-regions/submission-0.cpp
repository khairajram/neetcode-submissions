class Solution {
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    bool change(vector<vector<char>>& board,int i,int j){
        if(i <= 0 || j <= 0 || i >= board.size() - 1 || j >= board[0].size() - 1)
            return false;

        board[i][j] = 'v';
        bool allOk = true;

        for(auto x : dir){
            int ni = i + x.first;
            int nj = j + x.second;
            if(ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] == 'O' && !change(board,ni,nj)){
                allOk = false;
            }
        }

        if(allOk)
            board[i][j] = 'X';
        else
            board[i][j] = 'O';

        return true;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')
                    change(board,i,j);
            }
        }
    }
};
