//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int> adj[], int i,bool color,  vector<int>&col){
       
        col[i] = color;
        for(auto it:adj[i]){
            if(col[it]==-1){
                if(!dfs(adj, it, !color, col))return false;
            }
            else if(col[i]==col[it])return false;
            
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	  
	    vector<int> col(V, -1);
	
	    for(int i=0;i<V;i++){
	        if(col[i]==-1)
	        {
	            if(!dfs(adj, i, 0,  col))return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends