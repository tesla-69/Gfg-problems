//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<vector<int>> arr;
        int n = profit.size();
        for(int i = 0;i<n; i++) {
            arr.push_back({deadline[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        // int mxdead = -1;
        // for(int i = 0; i < n; i++) mxdead = max(mxdead, deadline[i]);
        // vector<int> hash(mxdead+1,-1);
        int jobs = 0;
        int maxprofit = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            if(jobs < arr[i][0]) {
                maxprofit += arr[i][1];
                pq.push(arr[i][1]);
                jobs++;
            }
            else if(arr[i][1] > pq.top()){
                maxprofit -= pq.top();
                pq.pop();
                maxprofit += arr[i][1];
                pq.push(arr[i][1]);
            }
        }
        return {jobs, maxprofit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends