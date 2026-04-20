class Solution {
    bool col(int i,int j,vector<string> &board){
        if(i < 0)
            return true;

        return (board[i][j] == '.' && col(i-1,j,board));
    }

    bool rightdiag(int i,int j,vector<string> &board,int n){
        if(i < 0 || j >= n)
            return true;

        return (board[i][j] == '.' && rightdiag(i-1,j+1,board,n));
    }

    bool leftdiag(int i,int j,vector<string> &board){
        if(i < 0 || j < 0)
            return true;

        return (board[i][j] == '.' && leftdiag(i-1,j-1,board));
    }

    bool diag(int i,int j,vector<string> &board,int n){
        return leftdiag(i,j,board) && rightdiag(i,j,board,n);
    }

    bool canput(int i,int j,vector<string> &board,int n){
        return diag(i,j,board,n) && col(i,j,board);
    }

    void solve(int n,vector<vector<string>> &ans,vector<string> &board,int i){
        if(i == n){
            ans.push_back(board);
            return;
        }

        for(int k=0;k<n;k++){
            if(canput(i,k,board,n)){
                board[i][k] = 'Q';
                solve(n,ans,board,i+1);
                board[i][k] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));

        solve(n,ans,board,0);

        return ans;
    }
};
