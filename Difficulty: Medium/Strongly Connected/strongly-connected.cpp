//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
    void dfs(int node, vector<vector<int>>&adj, stack<int>&s, vector<int>&vis){
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, s, vis);
            }
        }
        s.push(node);
    }
    void dfs2 (int node, vector<vector<int>>& adjT, vector<int>&vis) {
        vis[node] = 1;
        for(auto it: adjT[node]) {
            if(!vis[it]) dfs2(it, adjT, vis);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int> s;
        int n = adj.size();
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,adj,s,vis);
            }
        }
        vector<vector<int>> adjT(n);
        for(int i = 0; i<n; i++) {
            vis[i] = 0;
            for(auto it: adj[i]) {
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                dfs2(node, adjT, vis);
                scc++;
            }
        }
        return scc;
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends