class Solution {
  public:
    
    int solve(int i, int j, int n, vector<vector<int>>& arr,
    vector<vector<vector<int>>> &dp) {
        if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size()) 
            return 0;
        if(arr[i][j] == -1) return 0;
        if(n == 1) return 1;
        
        if(dp[i][j][n] != -1) return dp[i][j][n];
        
        int ans = 0;
        for(int ii = -1; ii <= 1; ii++) {
            for(int jj = -1; jj <= 1; jj++) {
                if(abs(ii) == 1 && abs(jj) == 1) continue;
                ans += solve(i+ii, j+jj, n-1, arr, dp);
            }
        }
        return dp[i][j][n] = ans;
        
    }
  
    int getCount(int n) {
        // code here
        vector<vector<int>> arr(4, vector<int>(3, 1));
        arr[3][0] = -1;
        arr[3][2] = -1;
        vector<vector<vector<int>>> dp(4, 
        vector<vector<int>>(3, vector<int>(n+1, -1)));
        int total = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(arr[i][j] == -1) continue;
                total += solve(i, j, n, arr, dp);
            }
        }
        return total;
    }
};