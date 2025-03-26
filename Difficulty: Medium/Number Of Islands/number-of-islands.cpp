//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet
{
    vector<int> parent, rank, size;

public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        disjointSet ds(n*m);
        vector<int> ans;
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(auto it : operators) {
            int r = it[0] , c = it[1];
            if(vis[r][c]) {
                ans.push_back(cnt);
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j<= 1; j++) {
                    if(abs(i) == 1 && abs(j) == 1) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < n && nc >=0 && nc < m) {
                        if(vis[nr][nc]) {
                            int node = r * m + c;
                            int adjnode = nr * m + nc;
                            if(ds.findUPar(node) != ds.findUPar(adjnode)) {
                                cnt--;
                                ds.unionByRank(node,adjnode);
                            }
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};






















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends