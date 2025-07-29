class Solution {
public:

    int findIndex(string &s, char ch) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ch) {
                return i;
            }
        }
        return -1; // Fix for missing return
    }

    int findSum(string &s, int start, int end) {
        int sum = 0;
        for (int i = start + 1; i < end; i++) {
            sum += s[i]; // ASCII value
        }
        return sum;
    }

    vector<int> asciirange(string& s) {
        vector<int> arr;
        unordered_map<char, bool> visited;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (!visited[ch]) {
                int lastIndex = findIndex(s, ch);
                visited[ch] = true;

                // Only if character repeats
                if (lastIndex != -1 && lastIndex != i) {
                    int sum = findSum(s, i, lastIndex);
                    if (sum != 0) {
                        arr.push_back(sum);
                    }
                }
            }
        }

        return arr;
    }
};