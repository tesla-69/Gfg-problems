//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>adjls, int node, int vis[]){
        vis[node] = 1;
        for(auto it : adjls[node]) {
            if(!vis[it]) dfs(adjls, it, vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = V;
        vector<vector<int>> adjls(n);
        for(int i = 0; i< n; i++) {
            for(int j =0; j<n ;j++){
                if(adj[i][j] == 1) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int vis[n] = {0};
        int cnt = 0;
        for(int i =0; i<n; i++){
            if(!vis[i]){
                dfs(adjls, i, vis);
                cnt++;
            } 
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends