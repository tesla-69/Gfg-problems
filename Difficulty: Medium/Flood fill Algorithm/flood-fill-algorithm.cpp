//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>& vis
    , vector<vector<int>>& copy, int color, int newColor, int n, int m){
        vis[i][j] = 1;
        copy[i][j] = newColor;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(abs(a) == 1 && abs(b) == 1) continue;
                int nsr = i + a;
                int nsc = j + b;
                if(nsr>=0 && nsr < n && nsc>=0 && nsc<m &&
                image[nsr][nsc] == color && !vis[nsr][nsc]){
                    dfs(nsr,nsc,image,vis,copy,color,newColor,n,m);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
    int sr, int sc, int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        vector<vector<int> > copy(n,vector<int>(m,0));
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                copy[i][j] = image[i][j];
            }
        }
        int color = image[sr][sc];
        
        dfs(sr,sc,image,vis,copy,color,newColor,n,m);
        
        return copy;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends