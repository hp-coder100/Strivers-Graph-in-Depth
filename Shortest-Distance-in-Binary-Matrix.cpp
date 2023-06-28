//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(grid[destination.first][destination.second]==0)return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[source.first][source.second] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, source});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();
            
            
            vector<vector<int>> dir = {{0, 1}, {1, 0},{-1, 0}, {0, -1}};
            for(auto it:dir){
                int x = node.first+it[0];
                int y = node.second+it[1];
                
                if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1 && ( dist[x][y]==-1 || dist[x][y] > dis+1)){
                    dist[x][y] = dis+1;
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        return dist[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends