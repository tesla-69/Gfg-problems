//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxprofit = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = prices.size();
        for(int i = n-1;i >=0; i--){
            maxi = max(maxi,prices[i]);
            int temp = maxi - prices[i];
            maxprofit = max(maxprofit,temp); 
        }
        return maxprofit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends