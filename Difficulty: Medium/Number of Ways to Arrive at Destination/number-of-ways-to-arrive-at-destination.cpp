//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    long long mod = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,INT_MAX), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>,
        greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        while(!pq.empty()) {
            auto it = pq.top();
            long long dis = it.first;
            long long node = it.second;
            pq.pop();
            
            for(auto it : adj[node]) {
                long long newnode = it.first;
                long long d = it.second;
                if(d + dis < dist[newnode]) {
                    dist[newnode]= d + dis;
                    pq.push({d+dis, newnode});
                    ways[newnode] = ways[node];
                }
                else if(d + dis == dist[newnode]) {
                    ways[newnode] = (ways[newnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]  % mod;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends