//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int,int>> q;
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i == n-1 || j==0 || j==m-1){
                    if(mat[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) == 1) continue;
                    
                    int nr = r + a;
                    int nc = c + b;
                    if(nr>=0 && nr<n && nc>=0 &&nc<m 
                    && !vis[nr][nc] && mat[nr][nc] == 'O'){
                        vis[nr][nc] =1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends