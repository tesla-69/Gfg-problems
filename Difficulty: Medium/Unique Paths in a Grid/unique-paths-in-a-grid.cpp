class Solution {
  public:
  
    int solve(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &arr) {
        if(n < 0 || m < 0) return 0;
        if(grid[n][m] == 1) return 0;
        if(n == 0 && m == 0) return 1;
        
        if(arr[n][m] != -1) return arr[n][m];
        
        int up = solve(grid, n-1, m, arr);
        int left = solve(grid, n, m-1, arr);
        return arr[n][m] = up + left;
    }
  
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr(n, vector<int>(m, -1));
        return solve(grid, n-1, m-1, arr);
    }
};