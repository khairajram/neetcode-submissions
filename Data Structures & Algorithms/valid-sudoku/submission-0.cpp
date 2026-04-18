class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        unordered_map<string,unordered_set<int>> sq(9);

        for(int i=0;i<9;i++){
            for(int j =0;j<9;j++){
                string st = to_string(i/3) + "_" + to_string(j/3);
                if(board[i][j] != '.' && (row[i].find(board[i][j]) != row[i].end() || col[j].find(board[i][j]) != col[j].end() || sq[st].find(board[i][j]) != sq[st].end()))
                    return false;
                else{
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sq[st].insert(board[i][j]);
                }
            }
        }

        return true;

    }
};
