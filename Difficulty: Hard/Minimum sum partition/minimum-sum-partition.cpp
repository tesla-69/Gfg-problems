class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum+=arr[i];
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i = 0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]]=true;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= sum; j++) {
                int nt = dp[i-1][j];
                int t = false;
                if(arr[i] <= j) t = dp[i-1][j - arr[i]];
                dp[i][j] = t || nt;
            }
        }
        int diff = INT_MAX;
        for(int i = 0; i<= sum; i++) {
            if(dp[n-1][i] == true) {
                int one = i;
                int sec = sum - i;
                diff = min(diff, abs(one - sec));
            }
        }
        return diff;
    }
};
