class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int a = mat1[i][j];
                // cout<<a<< " "<<x-a<< "     ";
                int k = 0;
                while(k < n && mat2[k][0] <= x - a) {
                    // cout<<mat2[k][0]<<" ";
                    k++;
                }
                
                // cout<<" "<<k<<" ";
                if(k > 0) {
                    for(int l = 0; l < n; l++) {
                        if(mat2[k-1][l] == x - a){
                            cnt++;
                            // cout<<l<<" "<<mat2[k-1][l];
                        } 
                    }
                }
                // cout<<endl;
            }
            // cout<<endl;
        }
        return cnt;
    }
};