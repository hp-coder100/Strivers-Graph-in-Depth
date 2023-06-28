#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> ti;
class Solution {
public: int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
       unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : a )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        // minHeap based on cost of distance from source
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, k+1 } ); // cost, vertex, hops
        
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if( curr == sink )
                return cost;

            if( stop > 0 )
                for( auto next : adjList[curr] )
                    minHeap.push( { cost+next.second, next.first, stop-1 } );
        }
        return -1; 
    }
};