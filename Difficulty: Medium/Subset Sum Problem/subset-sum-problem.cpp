//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{  
    
    bool solve(vector<int> &arr, int tar, int ind, vector<vector<int>>&dp) {
        if(tar == 0) return true;
        if(ind == 0) return arr[0] == tar;
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        bool nt = solve(arr, tar, ind - 1, dp);
        bool t = false;
        if(arr[ind] <= tar) t = solve(arr, tar - arr[ind], ind - 1, dp);
        
        return dp[ind][tar] = nt || t;
    }
    
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(arr, sum, n-1, dp);
        
        
        // int n= arr.size();
        // bool dp[n+1][sum+1];
        
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<sum+1;j++){
        //         if(i==0) dp[i][j] = false;
            
        //         if(j==0) dp[i][j] = true;
        //     }
        // }
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<sum+1;j++){
        //         if(arr[i-1] <= j) {
        //             dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        //         }
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[n][sum];
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends