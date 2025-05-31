class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int> pq;
        int n = mat.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j < n ; j++) {
                if(pq.size() < k) pq.push(mat[i][j]);
                else if (pq.top() > mat[i][j]) {
                    pq.pop();
                    pq.push(mat[i][j]);
                }
            }
        }
        return pq.top();
    }
};