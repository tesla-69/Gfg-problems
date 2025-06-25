class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> left(n, -1);    left[0] = arr[0];
        vector<int> right(n, -1);   right[n - 1] = arr[n - 1];
        int lval = arr[0], rval = arr[n - 1];
        for(int i = 1; i < n; i++){
            lval = max(lval, arr[i]);            
            left[i] = lval;
        }
        for(int i = n - 2; i > -1; i--){
            rval = max(rval, arr[i]);
            right[i] = rval;
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            int val = min(left[i], right[i]);
            if(val - arr[i] > 0)
                ans += val - arr[i];
        }
        return ans;
    }
};