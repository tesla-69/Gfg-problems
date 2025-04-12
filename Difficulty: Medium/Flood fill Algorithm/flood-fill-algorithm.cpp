//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int color = image[sr][sc];
        while(!q.empty()) {
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();
            image[r][c] = newColor;
            for(int i = -1; i<=1; i++) {
                for(int j = -1; j<= 1; j++) {
                    if(abs(i) == 1 && abs(j) == 1) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                        !vis[nr][nc] && image[nr][nc] == color) {
                            q.push({nr, nc});
                            vis[nr][nc] = 1;
                        }
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends