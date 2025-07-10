class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        unordered_map<string, int> mp;
        string ans;
        for(auto it: words) {
            mp[it]++;
            string s = it;
            string cur;
            for(auto i: s) {
                cur += i;
                if(mp[cur] == 0) {
                    cur = "";
                    break;
                }
            }
            if(cur != ""){
                if(cur.size() > ans.size()) ans = cur;
            } 
        }
        return ans;
    }
};