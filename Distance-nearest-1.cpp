//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    ////
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    /////
	    vector<int> dr;
	    vector<int> dc;
	    dr.push_back(-1);
	    dr.push_back(0);
	    dr.push_back(1);
	    dr.push_back(0);
	    
	    dc.push_back(0);
	    dc.push_back(1);
	    dc.push_back(0);
	    dc.push_back(-1);
	    
	    
	    /////
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        ans[row][col]=dist;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nrow=row+dr[i];
	            int ncol=col+dc[i];
	            
	            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&& !vis[nrow][ncol]){
	                q.push({{nrow,ncol},dist+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	        
	        
	    }
	    //////
	    
	    return ans;
	    
	}
	
// 	void dfs(int i, int j,vector<vector<int>>&grid,int steps){
// 	    int m=grid.size(),n=grid[0].size();
// 	    vector<pair<int,int>>dr={{-1,0},{0,-1},{0,1},{1,0}};
	        
// 	    for(auto r:dr){
// 	        int x=r.first+i,y=r.second+j;
// 	        if(x<0|| y<0|| x>=m|| y>=n )continue;
// 	        if(ans[x][y]>steps+1){
// 	            ans[x][y]=steps+1;
// 	            dfs(x,y,grid,steps+1);
// 	        }
// 	    }

// 	}
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends