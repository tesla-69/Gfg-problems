class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string up, low;
        for(auto it: s) {
            if(it >= 'A' && it <= 'Z') up += it;
            else low += it;
        }
        sort(up.begin(), up.end());
        sort(low.begin(), low.end());
        int i = 0, j = 0;
        for(int k = 0; k < s.length(); k++) {
            if(s[k] >= 'A' && s[k] <= 'Z') s[k] = up[i++];
            else s[k] = low[j++];
        }
        return s;
    }
};