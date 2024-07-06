//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > copy = grid;
        vector<vector<int> > vis(n,vector<int>(m,0));
    
        queue<pair<pair<int,int> , int> > q;
        for(int i = 0; i<n;i++) {
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) {
                    q.push({{i,j},1});
                    vis[i][j] = 1;
                    copy[i][j] = 0;
                }
                
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int a = -1;a<=1;a++){
                for(int b =-1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) ==1) continue;
                    
                    int nr = r +a;
                    int nc= c + b;
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] 
                    && grid[nr][nc] == 0 ){
                        copy[nr][nc] = dist;
                        vis[nr][nc] = 1;
                        q.push({{nr,nc},dist+1});
                    }
                }
            }
            
        }
        return copy;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends