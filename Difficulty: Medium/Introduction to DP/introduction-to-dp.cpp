class Solution {
    const int MOD = 1e9 + 7;
  public:
    long long int solve(vector<long long>& vt, int n){
        if(n == 0 || n == 1)
            return n;
        if(vt[n] != -1)     return vt[n];
        return vt[n] = (solve(vt, n - 1) + solve(vt, n - 2)) % MOD;
    }
    long long int topDown(int n) {
        // code here
        vector<long long> vt(n + 1, -1);
        return solve(vt, n);
    }

    long long int bottomUp(int n) {
        if(n == 0 || n == 1)
            return n;
        long long res = 0;
        long long prev2 = 0, prev1 = 1;
        for(int i = 2; i < n + 1; i++){
            res = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};