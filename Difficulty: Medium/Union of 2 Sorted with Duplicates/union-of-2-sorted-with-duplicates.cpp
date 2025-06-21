class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
         set<int> s;
        for(int i:a){
            s.insert(i);
        }
        for(int i:b){
            s.insert(i);
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
        // return vector with correct order of elements
    }
};