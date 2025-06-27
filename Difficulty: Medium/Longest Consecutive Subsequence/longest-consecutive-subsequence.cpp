class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = 1;
        int len = 1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i-1]) continue;
            if(arr[i] == arr[i-1] + 1) {
                len++;
                maxi = max(maxi, len);
            }
            else len = 1;
        }
        return maxi; 
    }
};