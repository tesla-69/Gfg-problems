//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> arr;
        for(int i = 0; i < start.size(); i++) 
            arr.push_back({start[i], finish[i]});
            
        sort(arr.begin(), arr.end(), [&](pair<int,int> &a, pair<int,int>&b){
            return a.second < b.second;
        });
        int n = start.size();
        int take = 1;
        int end = arr[0].second;
        for(int i = 1; i<n; i++) {
            if(arr[i].first > end) {
                take++;
                end = arr[i].second;
            }
        }
        return take;
        
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
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends