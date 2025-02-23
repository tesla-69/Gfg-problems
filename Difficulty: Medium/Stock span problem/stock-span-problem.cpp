//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++) {
            if(s.empty()) {
                s.push({arr[i],1});
                ans.push_back(1);
            }
            else {
                int cnt = 1;
                while(!s.empty() && s.top().first <= arr[i]) {
                    cnt += s.top().second;
                    s.pop();
                }
                s.push({arr[i],cnt});
                ans.push_back(cnt);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends