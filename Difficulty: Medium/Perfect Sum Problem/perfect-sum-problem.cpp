class Solution {
  public:
  
    int solve(int i, vector<int> &arr, int target, vector<vector<int>>& dp) {
        if (i == arr.size()) {
            return target == 0 ? 1 : 0;
        }
        
        if(i >= arr.size()) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int take = 0;
        if(arr[i] <= target) take = solve(i + 1, arr, target - arr[i], dp);
        int ntake = solve(i + 1, arr, target, dp);
        
        return dp[i][target] = take + ntake;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(0, arr, target, dp);
    }
};