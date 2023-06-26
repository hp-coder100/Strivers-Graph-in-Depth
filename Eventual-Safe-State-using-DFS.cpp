//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   bool dfs(int node,vector<int>&vis,vector<int>&path,vector<int> adj[],vector<int>&issafe){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,path,adj,issafe)){
                    return true;
                }
                
            }
            else if(path[it]){
                return true;
            }
        }
        issafe[node]=1;
        path[node]=0;
        return false;
        
    } 
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> issafe(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,path,adj,issafe);
                }
            }
            
            for(int i=0;i<V;i++){
                if(issafe[i]==1){
                    ans.push_back(i);
                }
            }
            
            return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends