class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            int val = arr[i];
            int left = i + 1, right = n - 1;
            while(left < right){
                int temp = val + arr[left] + arr[right];
                if(temp == target)
                    return true;
                else if(temp < target)
                    left++;
                else
                    right--;
            }
        }
        return false;
    }
};