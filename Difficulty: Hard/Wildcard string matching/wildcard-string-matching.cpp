class Solution{
private:
    int dp[1001][1001];
    
    bool solve(int i, int j, string &s1, string &s2) {
        if(i == s1.size() and j == s2.size()) return true;
        if(i == s1.size()) return false;
        if(j == s2.size()) {
            if(i == s1.size()-1 and s1.back() == '*') return true;
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if(s1[i] == s2[j] or s1[i] == '?') {
            ans = solve(i+1, j+1, s1, s2);
        } else if(s1[i] == '*') {
            ans = solve(i, j+1, s1, s2) 
                or solve(i+1, j+1, s1, s2) 
                or solve(i+1, j, s1, s2);
        }
        
        return dp[i][j] = ans;
    }
public:
    bool match(string wild, string pattern) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, wild, pattern);
    }
};