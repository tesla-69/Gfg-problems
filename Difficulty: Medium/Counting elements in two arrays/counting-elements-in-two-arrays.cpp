class Solution {
  public:
    vector<int> countLessEq(vector<int>& arr, vector<int>& brr) {
        // code here
        int n = arr.size(); int m = brr.size();
        sort(brr.begin(), brr.end());
        vector<int> ans(n);
        int ptr = 0;
        for(auto &i : arr) {
            int cnt = upper_bound(brr.begin(), brr.end(), i) - brr.begin();
            ans[ptr++] = cnt;
        }
        return ans;
        
    }
};