//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
    stack<int> s;  // Use stack<int> instead of stack<char>
        
        for (auto str : arr) {
            if (str != "+" && str != "-" && str != "/" && str != "*") {  
                s.push(stoi(str));  // Push numbers as integers
            } 
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int result = 0;
                
                if (str == "+") result = a + b;
                else if (str == "-") result = a - b;
                else if (str == "*") result = a * b;
                else if (str == "/") result = a / b;
                
                s.push(result);
            }
        }
        
        return s.top();  // Return the final result
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends