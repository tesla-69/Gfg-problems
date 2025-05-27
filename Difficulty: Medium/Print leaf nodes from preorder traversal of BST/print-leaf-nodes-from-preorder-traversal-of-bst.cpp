class Solution {
  public:
    vector<int> leafNodes(vector<int>& pre) {
        // code here
        stack<int> s;
        int n = pre.size();
        vector<int> ans;
        s.push(pre[0]);
        for(int i = 1; i < n; i++) {
            if(s.top() < pre[i]) {
                int cnt = 0;
                if(s.top() < pre[i]) {
                    int temp = s.top();
                    while(!s.empty() && s.top() < pre[i]) {
                        s.pop();
                        cnt++;
                    }
                    s.push(pre[i]);
                    if(cnt >= 2) ans.push_back(temp);
                }
            }
            else {
                s.push(pre[i]);
            }
        }
        ans.push_back(pre[n-1]);
        return ans;
    }
};