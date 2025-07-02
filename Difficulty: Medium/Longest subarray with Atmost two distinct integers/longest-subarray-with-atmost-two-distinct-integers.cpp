class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = 0;
        int curr = 0;
        unordered_set<int> st;
        unordered_map<int, int> mp;
        st.insert(arr[0]);
        mp[arr[0]]++;
        int i = 0;
        int j = 1;
        while(j < n) {
            if(st.find(arr[j]) != st.end()) {
                mp[arr[j]]++;
                // j++;
            }
            else {
                // cout<<j<< " "<< st.size() <<endl;
                while(i < j && st.size() == 2) {
                    if(mp[arr[i]] > 0) {
                        mp[arr[i]]--;
                        if(mp[arr[i]] == 0) {
                            st.erase(arr[i]);
                        }
                    }
                    // cout<<i<<" ";
                    i++;
                }
                st.insert(arr[j]);
                mp[arr[j]]++;
                // cout<<endl;
            }
            maxi = max(j - i + 1, maxi);
            j++;
        }
        return maxi;
    }
};