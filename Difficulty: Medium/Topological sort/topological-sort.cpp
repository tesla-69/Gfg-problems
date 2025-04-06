//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    void dfs(vector<vector<int>> &adj, int node, vector<int>& topo, vector<int>&vis){
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) dfs(adj, it, topo, vis);
        }
        topo.push_back(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> topo;
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V,0);
        for(int i =0;i<V;i++) {
            if(!vis[i]) {
                dfs(adj,0,topo,vis);
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends