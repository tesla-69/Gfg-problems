class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> squares;
        int n = arr.size();

        for(int i = 0; i < n; ++i) {
            squares.insert(arr[i] * arr[i]);
        }

        // Try all pairs
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int sumSquares = arr[i]*arr[i] + arr[j]*arr[j];
                if(squares.count(sumSquares)) {
                    return true;
                }
            }
        }

        return false;
    }
};
