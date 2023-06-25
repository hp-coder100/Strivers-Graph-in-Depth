//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1,0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1},{1, -1}};
        for(auto d:dir){
            int x = i+d[0];
            int y= j+d[1];
            
            
            if(x<n && x>=0 && y<m && y>=0 && grid[x][y]=='1' && !vis[x][y]){
                dfs(grid, n, m, x, y, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid,n, m, i, j, vis);
                    cnt++;}
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends