//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countWays(int n) {
        vector<int> arr(n + 1, -1); // Ensure the array size is exactly needed
        
        return helper(n, arr);
    }

private:
    int helper(int n, vector<int>& arr) {
        if (n == 0 || n == 1) return 1;
        if (arr[n] != -1) return arr[n];

        return arr[n] = helper(n - 1, arr) + helper(n - 2, arr);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends