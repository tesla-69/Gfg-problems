class Solution {
  public:
    int fact(int n) {
        int ans = 1;
        for(int i = n; i>=2; i--) ans = ans*i;
        return ans;
    }
    int countStrings(string &s) {
        // code here
        vector<int> arr;
        unordered_map<char, int> mp;
        for(auto it: s){
            mp[it]++;
        } 
        int n = s.size();
        int ans = (n*(n-1))/2;
        for(auto it: mp) {
            int num = it.second;
            if(num > 1) ans -= (num*(num-1))/2;
        }
        return ans + (ans == (n*(n-1))/2 ? 0 : 1);
    }
};
