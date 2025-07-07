class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int>s;
        int n = arr.size();
        vector<int> nge(2*n);
        for(int i = 0; i < n; i++) arr.push_back(arr[i]);
        
        s.push(-1);
        for(int i = 2*n - 1; i >= 0; i--) {
            while(s.top() != -1 && s.top() <= arr[i]) {
                s.pop();
            }
            nge[i] = s.top();
            s.push(arr[i]);
        }
        // for(auto it: arr) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: nge) cout<<it<<" ";
        // cout<<endl;
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(nge[i]);
        return ans;
        
    }
};