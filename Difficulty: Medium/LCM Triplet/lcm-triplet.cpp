class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n<3)return n; // Cases with n = 1 and n = 2
        if(n%2)return n*(n-1)*(n-2);
        int ans = 0;
        for(int i = 3;i<=n;i++){
            for(int j = i-2;j>=1;j--){
                int prod = i*(i-1)*j; 
                int gcd = __gcd(i, j); 
                ans = max(ans, prod/gcd);
            }
        }
        
        return ans;
    }
};