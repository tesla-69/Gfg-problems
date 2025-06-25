class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        if(n==0)
        return 0;
        int dirs[4][2] ={{-1,0},{1, 0},{0,-1},{0,1}};
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty()) {
            auto rec=pq.top();
            pq.pop();
            int cur=rec.first;
            int x=rec.second.first;
            int y=rec.second.second;
            if(x==n -1 && y==n-1) 
                return cur;
            if(cur>dist[x][y]) 
                continue;
            for(int i=0; i<4;++i) {
                int nx= x+dirs[i][0];
                int ny=y+dirs[i][1];
                if(nx>=0 && nx <n && ny>=0 && ny<n) {
                    int new_cost=cur +grid[nx][ny];
                        if (new_cost<dist[nx][ny]) {
                        dist[nx][ny]=new_cost;
                        pq.push({new_cost, {nx, ny}});
                    }
                }
            }
        }
        
        return dist[n-1][n-1];
        
    }
};