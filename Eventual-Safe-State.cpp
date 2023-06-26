//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int N, vector<int> newadj[]) {
        // code here
        vector<int> adj[N];
        for(int i=0;i<N;i++){
            for(auto it:newadj[i]){
                adj[it].push_back(i);
            }
        }
        
        
        vector<int> indeg(N);
        
        for(int i=0;i<N;i++){
            for(auto it:adj[i])indeg[it]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<N;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:adj[front]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
            ans.push_back(front);
        }
        sort(ans.begin(), ans.end());
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