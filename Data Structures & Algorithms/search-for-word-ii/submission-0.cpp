class Node{
    public:
    string word;
    vector<Node*> next;    

    Node(){
        word = "";
        next = vector<Node*>(26,nullptr);
    }
};


class Solution {

    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(vector<vector<char>>& board,int i,int j,Node* root,vector<string> &ans){

        char ch = board[i][j];

        if(ch == '#' || !root->next[ch - 'a'])
            return;

        root = root->next[ch - 'a'];

        if(root->word != ""){
            ans.push_back(root->word);
            root->word = "";
        }

        board[i][j] = '#';

        int n = board.size();
        int m = board[0].size();

        for(int p=0;p<4;p++){

            int x = i + dir[p][0];
            int y = j + dir[p][1];

            if(x >=0 && x<n && y>=0 && y<m)
                dfs(board, x, y, root, ans);
        }

        board[i][j] = ch;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();

        for(auto &w : words){

            Node* curr = root;

            for(auto ch : w){
                int idx = ch - 'a';

                if(!curr->next[idx])
                    curr->next[idx] = new Node();
                
                curr = curr->next[idx];
            }

            curr->word = w;
        }

        vector<string> ans;

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs(board,i,j,root,ans);

        return ans;
    }
};
