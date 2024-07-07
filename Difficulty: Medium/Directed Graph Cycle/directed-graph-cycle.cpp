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
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
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