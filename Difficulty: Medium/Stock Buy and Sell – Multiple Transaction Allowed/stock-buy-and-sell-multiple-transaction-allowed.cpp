class Solution {
    public:
    int maximumProfit(vector<int> &arr) {
        // code here
        int low = 0;
        int high = 0;
        int profit = 0;
        
        
        // two pointer approach
        while(high <arr.size()-1){
            if(arr[high+1] >= arr[high]){
                high++;
            }
            else if(arr[high+1]<arr[high]){
                profit += arr[high]-arr[low];
                low = high+1;
                high++;
                
            }
        }
        if(high>low){
            profit += arr[high]-arr[low];
        }
        return profit;
    }
};