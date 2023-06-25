//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(vector<vector<char>> &mat,int n, int m, int i, int j, vector<vector<int>>&vis){
        vis[i][j] = 1;
        
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1,0}, {0, -1}};
        for(auto d:dir){
            int x = i+d[0];
            int y= j+d[1];
            
            
            if(x<n && x>=0 && y<m && y>=0 && mat[x][y]=='O' && !vis[x][y]){
                dfs(mat, n, m, x, y, vis);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(mat[i][j]=='O')dfs(mat,n, m, i, j, vis);
                }
            }
        }
        vector<vector<char>> ans = mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]=='O' && vis[i][j]==0)ans[i][j]='X';
                
            }
        }
        return ans;
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