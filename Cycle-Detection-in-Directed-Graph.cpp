//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[], int i, vector<int> &vis, vector<int> &path){
        vis[i] = 1;
        path [i] = 1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj, it, vis, path))return true;
            }
            else if(path[it])return true;
        }
        path[i]=0;
        return false;
    }  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), path(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj, i, vis, path))return true;
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends