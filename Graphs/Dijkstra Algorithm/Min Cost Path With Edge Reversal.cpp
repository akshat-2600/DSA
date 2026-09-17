/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

*/


/******************************************************** C++ ********************************************************/

// Approach : Dijkstra + 0-1 BFS
// T.C        : O(V + E)
// S.C        : O(V + E)

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);

        // adjacency matrix
        for (auto& edge : edges) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt, 0});  // original edge
            adj[v].push_back({u, wt, 1});  // reversed edge
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {cost, node}
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (u == n-1) return d;
            if (d > dist[u]) continue;

            for (auto &ngbr : adj[u]) {
                int v   = ngbr[0];
                int wt  = ngbr[1];
                int dir = ngbr[2];

                int move_cost = (dir == 1) ? 2 * wt : wt;

                if (dist[u] + move_cost < dist[v]) {
                    dist[v] = dist[u] + move_cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] != INT_MAX ? dist[n-1] : -1;
    }
};