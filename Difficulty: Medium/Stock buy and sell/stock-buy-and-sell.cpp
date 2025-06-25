// User function template for C++

class Solution {
  public:
    // Function to find the days of buying and selling stock for max profit.
    int stockBuySell(vector<int> &arr) {
        int buy = arr[0];
        int curmax = buy, n = arr.size();
        int maxprofit = 0, i = 1;
        
        while(i < n) {
            if(curmax < arr[i]) {
                curmax = arr[i];
                i++;
            } else {
                maxprofit += curmax - buy;
                buy = arr[i];
                curmax = buy;
                i++;
            }
        }
        maxprofit += curmax - buy;
        
        return maxprofit;
    }
};