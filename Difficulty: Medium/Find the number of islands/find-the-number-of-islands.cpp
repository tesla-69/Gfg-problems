//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    void bfs(int a, int b, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({a,b});
        vis[a][b] = 1;
        while(!q.empty()) {
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j<=1; j++) {
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]
                        && grid[nr][nc] == 'L'){
                            q.push({nr, nc});
                            vis[nr][nc] = 1;
                        }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 'L' && !vis[i][j]) {
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends