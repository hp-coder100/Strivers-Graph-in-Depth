//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &mat,int n, int m, int i, int j, vector<vector<int>>&vis){
        vis[i][j] = 1;
        
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1,0}, {0, -1}};
        for(auto d:dir){
            int x = i+d[0];
            int y= j+d[1];
            
            
            if(x<n && x>=0 && y<m && y>=0 && mat[x][y]==1 && !vis[x][y]){
                dfs(mat, n, m, x, y, vis);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(mat[i][j]==1)dfs(mat,n, m, i, j, vis);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && vis[i][j]==0)cnt++;
                
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends