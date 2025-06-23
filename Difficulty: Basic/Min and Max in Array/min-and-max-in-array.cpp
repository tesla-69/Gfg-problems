class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        pair<int,int> sol;
        sol.first = INT_MAX;
        sol.second = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if(sol.first > arr[i]) {
                sol.first = arr[i];
            }
    
            if(sol.second < arr[i]) {
                sol.second = arr[i];
            }
        }
        return sol;
    }
};