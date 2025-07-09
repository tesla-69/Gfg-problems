class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> s;
        s.push(-1);
        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && arr[s.top()] > arr[i]) s.pop();
            pse[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        s.push(n);
        for(int i = n-1; i >=0 ;i--) {
            while(s.top() != n && arr[s.top()] >= arr[i]) s.pop();
            nse[i] = s.top();
            s.push(i);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int a = abs(nse[i] - i);
            int b = abs(pse[i] - i);
            int temp = a * b;
            // cout<<temp<<" ";
            cnt += temp * arr[i];
        }
        return cnt;
    }
};