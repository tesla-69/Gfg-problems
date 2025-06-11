class Solution {
  public:
    int findLength(vector<int> &c, vector<int> &r) {
        // code here
        stack<pair<int,int>> st;
        int n = c.size();
        for(int i = 0; i < n; i++) {
            if(st.empty()) st.push({c[i], r[i]});
            else {
                auto it = st.top();
                int col = it.first;
                int rad = it.second;
                if(c[i] == col && r[i] == rad) st.pop();
                else st.push({c[i], r[i]});
            }
        }
        return st.size();
    }
};