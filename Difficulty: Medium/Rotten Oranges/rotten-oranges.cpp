//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<pair<int,int>,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i= 0;i<n;i++){
            for(int j= 0l;j<m;j++){
                if(mat[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i = -1;i<=1;i++){
                for(int j =-1;j<=1;j++){
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i;
                    int nc = c+j;
                    if(nr >= 0 && nr < n && nc < m && nc>=0 
                    && vis[nr][nc] == 0 && mat[nr][nc] == 1){
                        vis[nr][nc] = 2;
                        q.push({{nr,nc},t+1});
                    }
                }
            }
        }
        for(int i= 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return tm;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends