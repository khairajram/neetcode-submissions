class Solution {
    vector<int> dirx = {-1,0,1,0};
    vector<int> diry = {0,1,0,-1};
    bool path(vector<vector<char>>& board, string word,int i,int r,int c){
        if(i == word.size())
            return true;

        for(int p=0;p<4;p++){
            int nx = dirx[p] + r;
            int ny = diry[p] + c;

            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == word[i] && path(board,word,i+1,nx,ny))
                return true;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int,int>> q;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(word[0] == board[i][j])
                    q.push({i,j});
        
        while(!q.empty()){
            auto [r , c] = q.front();
            cout<<r<<" "<<c<<endl;
            q.pop();

            if(path(board,word,1,r,c))
                return true;
        }

        return false;
    }
};
