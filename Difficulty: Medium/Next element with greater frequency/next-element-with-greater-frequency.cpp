class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        stack<pair<int,int>> st;
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        st.push({-1, -1});
        vector<int> ans;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--) {
            while(st.top().first != -1 && st.top().second <= mp[arr[i]]) {
                st.pop();
            }
            ans.push_back(st.top().first);
            st.push({arr[i], mp[arr[i]]});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
