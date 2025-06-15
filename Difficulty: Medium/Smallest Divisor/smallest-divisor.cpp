class Solution {
  public:
  
    bool findSum(vector<int> &arr, int k, int num) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += (arr[i] % num == 0) ? arr[i] / num : (arr[i] / num) + 1;
        }
        return sum <= k;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = arr[n-1];
        int s = 1;
        int e = maxi;
        int ans = INT_MAX;
        while(s <= e) {
            int m = s + (e - s) / 2;
            // cout<<m<<" ";
            if(findSum(arr, k, m)) {
                ans = min(ans, m);
                e = m-1;
            }
            else s = m + 1;
        }
        // cout<<endl;
        return ans;
    }
};
