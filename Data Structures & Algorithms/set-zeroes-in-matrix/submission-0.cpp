class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> row;
        set<int> col;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            
        

        for(auto i : row)
            for(int j=0;j<m;j++)
                mat[i][j] = 0;
        

        for(auto i : col)
            for(int j=0;j<n;j++)
                mat[j][i] = 0;

    }
};
