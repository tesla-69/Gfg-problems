//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dist(1e5, 1e9);
        dist[start] = 0;
        q.push({0, start});
        while(!q.empty()) {
            auto it = q.front();
            int steps = it.first;
            int node = it.second;
            if(node == end) return steps;
            q.pop();
            for(auto it : arr) {
                int mul = (node * it) % 100000;
                if(steps + 1 < dist[mul]) {
                    dist[mul] = steps +  1;
                    q.push({steps + 1, mul});
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends