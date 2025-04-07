//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool dfs(vector<vector<int>> &adj , int vis[] , int pathvis[] , int node) {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(adj,vis,pathvis,it) == true) return true;
            }
            else if(pathvis[it] == 1) return true;
        }
        pathvis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        for(int i = 0; i<V;i++) {
            if(!vis[i]){
                if(dfs(adj,vis,pathvis,i) == true) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends