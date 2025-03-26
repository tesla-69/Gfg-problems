//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class disjointSet
{

public:
    vector<int> parent, rank, size;
    disjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// User function Template for C++

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        disjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int r = 0; r<n; r++) {
            for(int c= 0; c<m; c++) {
                if(grid[r][c] == 1 ) {
                    for(int i = -1; i<=1; i++) {
                        for(int j = -1; j<=1; j++) {
                            if(abs(i) == 1 && abs(j) == 1) continue;
                            int nr = r + i;
                            int nc = c + j;
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                                if(grid[nr][nc] == 1 ) {
                                    int node = r * m + c;
                                    int adjnode = nr *m + nc;
                                    ds.unionBySize(node,adjnode);
                                }
                            }
                        } 
                    }
                }
            }
        }
        int ans = 0;
        for(auto it : ds.size) {
            ans = max(ans, it);
        }
        for(int r = 0; r < n; r++) {
            for(int c = 0 ; c < m; c++) {
                if(grid[r][c] == 0) {
                    set<int> s;
                    for(int i = -1; i <= 1; i++) {
                        for(int j = -1; j <= 1; j++) {
                            if(abs(i) == 1 && abs(j) == 1) continue;
                            int nr = r + i;
                            int nc = c + j;
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                                int node = nr* m + nc;
                                if(grid[nr][nc] == 1) 
                                    s.insert(ds.findUPar(node));
                            }
                        }
                    }
                    int curr = 0;
                    for(auto it : s) {
                        curr += ds.size[it];
                    }
                    curr++;
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};




























//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends