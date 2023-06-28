#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();
            
            if(node.first==n-1 && node.second==m-1)return dis;
            vector<vector<int>> dir = {{0, 1}, {1, 0},{-1, 0}, {0, -1}};
            for(auto it:dir){
                int x = node.first+it[0];
                int y = node.second+it[1];
                
                if(x<n && x>=0 && y<m && y>=0 ){
                     int newEffort = max(abs(grid[node.first][node.second] - grid[x][y]), dis);

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[x][y])
                    {
                        dist[x][y] = newEffort;
                        pq.push({newEffort, {x, y}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};