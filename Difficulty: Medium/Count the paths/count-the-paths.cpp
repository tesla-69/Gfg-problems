class Solution {
  public:
    int dfs(vector<vector<int>>& adj, int node, int dest, vector<int>& dp) {
        if (node == dest) return 1;
        if (dp[node] != -1) return dp[node];

        int ways = 0;
        for (int neighbor : adj[node]) {
            ways += dfs(adj, neighbor, dest, dp);
        }
        return dp[node] = ways;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> dp(V, -1); // dp[i] = number of paths from i to dest
        return dfs(adj, src, dest, dp);
    }
};
