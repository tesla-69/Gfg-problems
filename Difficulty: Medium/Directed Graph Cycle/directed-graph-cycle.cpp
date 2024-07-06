//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool iscycle(int s , int vis[] , int pathvis[] , vector<int> adj[]){
        
        vis[s] = 1;
        pathvis[s] = 1;
        for(auto it : adj[s]){
            if(!vis[it]) {
                if(iscycle(it,vis,pathvis,adj) == true) return true;
            }
            else if(pathvis[it] == 1) return true;
        }
        pathvis[s] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        for(int i=0;i<V;i++) {
            if(!vis[i]){
                if(iscycle(i,vis,pathvis,adj)==true) return true;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends