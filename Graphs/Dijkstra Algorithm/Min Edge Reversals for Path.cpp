/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/minimum-edges/1

*/


/******************************************************** C++ ********************************************************/

// Approach : Dijkstra + 0-1 BFS
// T.C        : O(V + E)
// S.C        : O(V + E)

class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n+1);
        
        // adjacency matrix
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back({v, 0}); // original edge cost 0
            adj[v].push_back({u, 1}); // reversed edge cost 1
        }
        
        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        
        deque<int> dq;
        dq.push_front(src);
        
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            
            if (u == dst) return dist[dst];
            
            for (auto &ngbr : adj[u]) {
                int v  = ngbr.first;
                int wt = ngbr.second;
                
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    
                    if (wt == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
        
    }
};