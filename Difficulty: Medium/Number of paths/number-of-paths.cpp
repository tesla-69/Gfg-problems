class Solution {
  public:
  
    int solve(int n, int m, vector<vector<int>> &arr) {
        if(n == 0 && m == 0) {
            return 1;
        }
        if(n < 0 || m < 0) return 0;
        
        if(arr[n][m] != -1) return arr[n][m];
        
        int up = solve(n-1, m, arr);
        int left = solve(n, m-1, arr);
        
        return arr[n][m] = up + left;
    }
  
  
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>> arr(m, vector<int>(n, -1));
        return solve(m-1, n-1, arr);
    }
};
