//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends