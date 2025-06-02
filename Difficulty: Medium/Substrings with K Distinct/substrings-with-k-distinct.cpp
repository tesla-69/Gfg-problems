class Solution {
  public:
    int atMostK(string& s, int k) {
        vector<int> count(26, 0);
        int i = 0, j = 0, n = s.size();
        int distinct = 0, ans = 0;

        while (j < n) {
            if (count[s[j] - 'a'] == 0) distinct++;
            count[s[j] - 'a']++;

            while (distinct > k) {
                count[s[i] - 'a']--;
                if (count[s[i] - 'a'] == 0) distinct--;
                i++;
            }

            ans += (j - i + 1); // all substrings ending at j with at most k distinct
            j++;
        }

        return ans;
    }

    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
