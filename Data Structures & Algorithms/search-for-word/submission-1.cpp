class Solution {
    vector<int> dirx = {-1,0,1,0};
    vector<int> diry = {0,1,0,-1};
    bool path(vector<vector<char>>& board, string word,int i,int r,int c){
        if(i == word.size())
            return true;

        char temp = board[r][c];
        board[r][c] = '#';

        for(int p=0;p<4;p++){
            int nx = dirx[p] + r;
            int ny = diry[p] + c;

            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == word[i] && path(board,word,i+1,nx,ny))
                return true;
        }

        board[r][c] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(word[0] == board[i][j])
                    if(path(board,word,1,i,j))
                        return true;
        

        return false;
    }
};
