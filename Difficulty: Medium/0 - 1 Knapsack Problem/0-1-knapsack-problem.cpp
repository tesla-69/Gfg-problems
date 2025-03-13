//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
       int w=W;
       int arr[n+1][w+1];
       for(int i=0;i<n+1;i++) {
           for(int j=0;j<w+1 ; j++){
               if(i==0 || j==0) arr[i][j]=0;
           }
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=w;j++){
               if(wt[i-1]<=j) {
                   arr[i][j] = max(val[i-1]+arr[i-1][j-wt[i-1]], arr[i-1][j]);
               }
               else arr[i][j] = arr[i-1][j];
           }
       }
       return arr[n][w];
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends