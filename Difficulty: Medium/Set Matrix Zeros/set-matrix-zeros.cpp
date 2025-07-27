class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        map<int, int> row, col;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(row[i] > 0) {
                for(int j = 0; j < m; j++) {
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            if(col[i] > 0) {
                for(int j = 0; j < n; j++) {
                    mat[j][i] = 0;
                }
            }
        }
    }
};