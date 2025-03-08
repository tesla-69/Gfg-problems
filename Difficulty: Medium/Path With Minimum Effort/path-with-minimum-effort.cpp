//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(rows, vector<int>(columns,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()) {
            auto it = pq.top();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r == rows - 1 && c == columns-1) return effort;
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(abs(i) == 1 && abs(j) == 1) continue;
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < columns) {
                        int newEffort = 
                        max(abs(heights[nr][nc] - heights[r][c]), effort);
                        if(newEffort < dist[nr][nc]) {
                            dist[nr][nc] = newEffort;
                            pq.push({newEffort, {nr,nc}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends