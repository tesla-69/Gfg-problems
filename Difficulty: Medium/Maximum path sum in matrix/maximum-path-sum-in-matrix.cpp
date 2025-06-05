// User function Template for C++

class Solution {
  public:
    int maximumPath(vector<vector<int>>& vec) {
        // code here
        int n = vec.size();
        int m = vec[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = INT_MIN;
    
        for(int i = 0; i<m; i++) {
            dp[n-1][i] = vec[n-1][i];
        }
    
        for(int i = n-2; i>=0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int d = dp[i+1][j];
                int dr = INT_MIN, dl = INT_MIN;
                if(j < m-1) dr = dp[i+1][j+1];
                if(j > 0) dl = dp[i+1][j-1];
    
                dp[i][j] = max({d, dr, dl}) + vec[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            ans = max(ans, dp[0][i]);
        }
        return ans;
    }
};