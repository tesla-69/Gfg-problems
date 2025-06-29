class Solution {
  public:
  
    int countStudents(vector<int>&arr, int limitsum) {
        int sum = 0;
        int students = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(sum + arr[i] <= limitsum) sum += arr[i];
            else {
                students++;
                sum = arr[i];
            }
        }
        return students;
    } 
  
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int students = countStudents(arr, mid);
            if(students > k) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
        
        
    }
};