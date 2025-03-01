//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        string ans;
        stack<int> st;
        stack<string> ss;
        for(int i =0;i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                } 
                i--;
                st.push(num);
            }
            else if(s[i] == ']') {
                int num = st.top();
                st.pop();
                string curr;
                string temp;
                while(ss.top() != "[") {
                    curr+=ss.top();
                    ss.pop();
                }
                ss.pop();
                while(num--) temp += curr;
                ss.push(temp);
            }
            else {
                string temp;
                temp += s[i];
                ss.push(temp);
            }
        }
        while(!ss.empty()) {
            ans += ss.top();
            ss.pop();
        }
        // ans = ss.top();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends