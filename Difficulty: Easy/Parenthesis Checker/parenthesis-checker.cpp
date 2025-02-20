//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else{
                if(st.empty()) return false;
                else if(st.top()=='(' && it==')' || st.top()=='{' && it=='}' || st.top()=='[' && it==']'){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends