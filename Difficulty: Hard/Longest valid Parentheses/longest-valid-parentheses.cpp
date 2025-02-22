//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here 
        int left = 0;
        int right = 0;
        int ans = 0;
        stack<char> st;
        for(auto ch : s) {
            if(ch == '(' ) left++;
            else if(ch == ')') right++;
            if(left == right) ans = max(ans,left*2);
            else if(right > left) {
                right = 0;
                left = 0;
            }
        }
        reverse(s.begin(),s.end());
        left = 0, right = 0;
        for(auto ch : s) {
            if(ch == '(' ) left++;
            else if(ch == ')') right++;
            if(left == right) ans = max(ans,left*2);
            else if(left > right) {
                right = 0;
                left = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends