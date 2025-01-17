//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int pro = 1;
        vector<int> ans;
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) cnt++;
            else pro *= arr[i];
        }
        if(cnt>=2) {
            vector<int> a(n,0);
            return a;
        }
        if(cnt == 1) {
            for(int i = 0; i< n ; i++) {
                if(arr[i] == 0) ans.push_back(pro);
                else 
                ans.push_back(0);
            }
            return ans;
        }
        for(int i =0 ; i < n; i++){
            int t = pro / arr[i] ;
            ans.push_back(t);
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends