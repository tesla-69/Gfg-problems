//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int i, vector<int> &arr, vector<int>&dp) {
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = arr[i] + min(solve(i+1, arr,dp), solve(i+2,arr,dp));
    } 
  
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        vector<int>dp(cost.size()+1,-1);
        return min(solve(0,cost,dp), solve(1,cost,dp));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends