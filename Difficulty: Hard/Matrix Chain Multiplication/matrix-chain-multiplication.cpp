//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int> > dp;
    Solution() : dp(101 , vector<int>(101,-1)){}
    int solve(int arr[] , int i , int j){
        
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = INT_MAX;
        
        for(int k = i ; k<=j-1;k++) {
            int temp = solve(arr , i, k) + solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
          
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N-1;
        int ans = solve(arr , i , j);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends