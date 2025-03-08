//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src,
    int dst, int K)  {
        // Code here
        int k = K;
        queue<pair<int,pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n,1e9);
        pq.push({0, {src,0}});
        dist[src] = 0;
        while(!pq.empty()) {
            auto it = pq.front();
            int stops = it.first;
            int station = it.second.first;
            int cost = it.second.second;
            pq.pop();
            if(stops > k) continue;
            for(auto it : adj[station]) {
                int nextStation = it.first;
                int price = it.second;
                int newCost = price + cost;
                if(newCost < dist[nextStation] && stops<=k) {
                    dist[nextStation] = newCost;
                    pq.push({stops+1,{nextStation, newCost}});
                }
            }
        }
        if(dist[dst] == 1e9)
        return -1;
        else return dist[dst];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends