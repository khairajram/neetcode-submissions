class Solution {
    bool binSch(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int end = n*m - 1;

        while(st <= end){
            int mid = st + (end - st)/2;
            int i = mid/m;
            int j = mid%m;

            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                end = mid - 1;
            else
                st = mid + 1;
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binSch(matrix,target);
    }
};
