//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size(), m=image[0].size();
        int color = image[sr][sc];
        vector<vector<int>> newImage = image;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                newImage[x][y] = newColor;
                int row[4] = {-1, 1, 0, 0};
                int col[4] = {0, 0, -1, 1};
                for(int k=0;k<4;k++){
                    
                    int i= x+row[k];
                    int j= y+col[k];
                    
                    if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color && vis[i][j]==0){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            
        }
        return newImage;
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