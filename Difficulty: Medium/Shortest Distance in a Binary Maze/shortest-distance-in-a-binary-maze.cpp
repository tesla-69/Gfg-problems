//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>> pq;
        dist[source.first][source.second] = 0;
        pq.push({0,{source.first,source.second}});
        while(!pq.empty()) {
            auto it = pq.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            for(int i =-1; i<=1; i++) {
                for(int j= -1; j<=1 ; j++) {
                    if(abs(i) == 1 && abs(j) == 1) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        if(dist[nr][nc] > dis + 1) {
                            dist[nr][nc] = dis + 1;
                            pq.push({dis + 1, {nr,nc}});
                        }
                    }
                }
            }
        }
        if(dist[destination.first][destination.second] == 1e9) return -1;
        else return dist[destination.first][destination.second];
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends