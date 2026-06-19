class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        int t = 0;
        int r = m - 1;
        int b = n - 1;
        int l = 0;
        vector<int> ans;

        while(t <= b && l <= r && cnt < m*n){
            
            int i = l;

            while(i<=r && cnt < m*n){
                ans.push_back(mat[t][i++]);
                cnt++;
            }
            t++;
            
            i = t;

            while(i<=b && cnt < m*n){
                ans.push_back(mat[i++][r]);
                cnt++;
            }
            r--;

            i = r;

            while(i>=l && cnt < m*n){
                ans.push_back(mat[b][i--]);
                cnt++;
            }
            b--;

            i = b;

            while(i>=t && cnt < m*n){
                ans.push_back(mat[i--][l]);
                cnt++;
            }
            l++;

        }

        return ans;
    }
};
