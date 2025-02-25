//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        map<int,int> mp;
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        for(int i =0;i<n;i++){
            sum += arr[i];
            if(sum == 0) cnt++;
            if(mp.find(sum) != mp.end()) cnt += mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends