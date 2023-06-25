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
        int n=grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        int freshOranges = 0;
        int rotten = 0;
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    freshOranges++;
                }
                else if(grid[i][j]==2){
                    rotten++;
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        int t = 0;
        while(!q.empty()){
            
            int size=q.size();
            cnt+=size;
            for(int s=0;s<size;s++){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                int row[4] = {-1, 1, 0, 0};
                int col[4] = {0, 0, -1, 1};
                for(int k=0;k<4;k++){
                    
                    int i= x+row[k];
                    int j= y+col[k];
                    
                    if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1 && vis[i][j]==0){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
                
               
            }
            t++;
            
        }
        
        if(cnt-rotten==freshOranges)return t-1;
        return -1;
        
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