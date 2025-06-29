// User function template for C++

class Solution {
  public:
  int countStudents(vector<int> &arr, int limitsum) {
        int sum = 0;
        int len = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(sum + arr[i] <= limitsum) sum += arr[i];
            else {
                len++;
                sum = arr[i];
            }
        }
        return len;
    }
  
    int splitArray(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int len = countStudents(arr, mid);
            if(len > k) {
                // ans = min(ans, mid);
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            } 
        }
        return ans;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        return splitArray(arr ,k);
        // return minimum time
    }
};