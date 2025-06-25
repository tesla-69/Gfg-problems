class Solution {
  public:
  
    bool solve(int i, int j, string& txt, string &pat, vector<vector<int>>& dp){
        if(i < 0) {
            for(int k = j; k >= 0; k--) {
                if(pat[k] != '*') return false;
            }
            return true;
        }
        if(j < 0) {
            return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        
        if(txt[i] == pat[j] || pat[j] == '?') {
            ans = solve(i-1, j-1, txt, pat, dp);
        }
        else if(pat[j] == '*') {
            ans = solve(i, j-1, txt, pat, dp) || solve(i-1, j, txt, pat, dp);
        }
        
        return dp[i][j] = ans;
        
    }
  
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, txt, pat, dp);
    }
};









