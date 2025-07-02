class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        if(arr.size() == 1) return arr.front();
        
        long long int ans = 1;
        
        long long int greaterNeg = -1e9, mod = 1e9 + 7;
        int zero = 0, negCount = 0;
        
        for(auto &ele : arr) {
            if(ele == 0) {
                zero++;
            } else {
                ans *= ele;
                ans %= mod;
                if(ele < 0){
                    negCount++;
                    greaterNeg = max(greaterNeg,(long long int)ele);
                }
            }
        }
        
        if(zero == arr.size()) return 0;
        
        if(negCount == 1 and zero == 1 and arr.size() == 2) return 0;
        
        if(ans < 0) ans /= greaterNeg;
        
        return ans;
    }
};