//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        // code here
        
        vector<int> indeg(N);
        
        for(int i=0;i<N;i++){
            for(auto it:adj[i])indeg[it]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<N;i++){
            if(indeg[i]==0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:adj[front]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
            cnt++;
        }
        return !(cnt==N);
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