class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int i = 0; 
        int j = 0;
        unordered_set<int> st;
        unordered_map<int, int> mp;
        while(j < n && st.size() != k) {
            st.insert(s[j]);
            mp[s[j]]++;
            j++;
        }
        if(j == n && st.size() < k) return -1;
        int maxi = j - i;
        // cout<<j<<" ";
        while(j < n) {
            if(st.find(s[j]) != st.end()){
                mp[s[j]]++;
            }
            else {
                while(st.size() == k) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        st.erase(s[i]);
                    }
                    i++;
                }
                mp[s[j]]++;
                st.insert(s[j]);
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};