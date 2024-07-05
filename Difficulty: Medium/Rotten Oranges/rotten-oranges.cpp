//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int> > copy = grid;
        queue< pair< pair<int,int> ,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int> > vis (n,vector<int>(m,0));
        int cntf=0;
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(copy[i][j] == 2) {
                    q.push({{i,j},0});
                    // vis[i][j] = 1;
                }
                else if(copy[i][j] == 1) cntf++;
            }
        } 
        int tm = 0;
        int cnt=0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t); 
            for(int a=-1;a<=1;a++){
                for(int b= -1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) == 1) continue;

                    int nr = r + a;
                    int nc = c + b;

                    if(nr>=0 && nr<n && nc>=0 && nc<m && copy[nr][nc] == 1 ){
                        copy[nr][nc] = 2;
                        // vis[nr][nc] = 1;
                        q.push({{nr,nc},t+1});
                        cnt++;
                    }
                }
            }
        }
        if(cnt != cntf) return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends