//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int> fo(26, -1), lo(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(fo[s[i] - 'a'] == -1){
                fo[s[i] - 'a'] = i;
                lo[s[i] - 'a'] = i;
            } 
            else lo[s[i] - 'a'] = i;
        }
        int cnt = 0;
        int i = 0;
        int currs = 0;
        int curre = lo[s[i] - 'a'];
        while(i < n) {
            while(i <= curre) {
                if(lo[s[i] - 'a'] > curre) curre = lo[s[i] - 'a'];
                i++;
            }
            cnt++;
            curre = lo[s[i] - 'a'];
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends