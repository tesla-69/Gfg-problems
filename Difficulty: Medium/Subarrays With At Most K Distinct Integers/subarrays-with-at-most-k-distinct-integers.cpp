class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
         int n = arr.size();
        unordered_map<int, int> freq;
        int i = 0, res = 0;

        for (int j = 0; j < n; j++) {
            freq[arr[j]]++;

            while (freq.size() > k) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    freq.erase(arr[i]);
                }
                i++;
            }

            res += j - i + 1;
        }

        return res;
    }
};