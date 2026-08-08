/*
    Company Tags        : 
    GeeksForGeeks Link  :  https://www.geeksforgeeks.org/problems/level-of-nodes1147/1

/************************************************************ C++ ************************************************************/

/* 
Time Complexity

Building Graph:       O(E)
Dijkstra's Algorithm: O((V + E) log V) (commonly written as O(E log V))
Overall:              O(E log V)

*/

/*
Space Complexity

Adjacency List : O(V + E)
Distance Array : O(V)
Visited Array  : O(V)
Priority Queue : O(V)

Overall Space Complexity: O(V + E)

*/

class Solution {
  public:
  
    // Function to find the shortest distance from src to dest
    // using Dijkstra's Algorithm
    int dijkstra(int src, int dest,
                unordered_map<int, vector<pair<int, int>>> &adj,
                vector<int>& dist,
                vector<bool>& visited) {
    
        // If source and destination are the same
        if (src == dest) {
            return 0;
        }
        
        // Min Heap
        // {current distance from source,  current node}
        priority_queue<pair<int, int>,
                      vector<pair<int, int>>,
                      greater<pair<int, int>>> q;
                      
        
        // Distance from source to itself is 0
        dist[src] = 0;
        q.push({0, src});
        
        // Process nodes until heap becomes empty
        while (!q.empty()) {
            
            // Get the node having minimum distance
            auto top = q.top();
            q.pop();
            
            int wt = top.first;   // Current shortest distance
            int u  = top.second;  // Current node
            
            // If node is already processed, skip it
            if (visited[u]) {
                continue;
            }
            
            // Mark current node as visited
            visited[u] = true;
            
            // If destination is reached, return its shortest distance
            if (u == dest) {
                return dist[dest];
            }
            
            // Traverse all adjacent nodes
            for (auto& vec: adj[u]) {
                int v = vec.first;  // Adjacent node
                int d = vec.second; // Edge weight
                
                // Process only if neighbour is not visited
                if (!visited[v]) {
                    //Relaxation Step
                    // If a shorter path is found, update the distance
                    if (wt + d < dist[v]) {
                        dist[v] = wt + d;
                        
                        // Push updated distance into the priority queue
                        q.push({dist[v], v});
                    }
                }
            }
        }
        
        // If destination isunreachable, return -1
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
  
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        
        // Adjacency List
        // node -> {neighbour, weight}
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Build an undirected graph
        for (auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Distance array
        // Initially every node is unreachable
        vector<int> dist(V, INT_MAX);
        
        // Visited array
        vector<bool> visited(V, false);
        
        // Run Dijkstra's Algorithm
        return dijkstra(src, dest, adj, dist, visited);
        
    }
};


/************************************************************ Java ************************************************************/

 /* 
Time Complexity

Building Graph:       O(E)
Dijkstra's Algorithm: O((V + E) log V) (commonly written as O(E log V))
Overall:              O(E log V)

*/

/*
Space Complexity

Adjacency List : O(V + E)
Distance Array : O(V)
Visited Array  : O(V)
Priority Queue : O(V)

Overall Space Complexity: O(V + E)

*/

import java.util.*;

class Solution {

    // Function to find the shortest distance from src to dest
    // using Dijkstra's Algorithm
    public int dijkstra(int src, int dest,
                        HashMap<Integer, ArrayList<int[]>> adj,
                        int[] dist,
                        boolean[] visited) {

        // If source and destination are the same
        if (src == dest) {
            return 0;
        }

        // Min Heap
        // {current distance from source, current node}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Distance from source to itself is 0
        dist[src] = 0;
        pq.offer(new int[]{0, src});

        // Process nodes until priority queue becomes empty
        while (!pq.isEmpty()) {

            // Get the node having minimum distance
            int[] top = pq.poll();

            int wt = top[0]; // Current shortest distance
            int u = top[1];  // Current node

            // If node is already processed, skip it
            if (visited[u]) {
                continue;
            }

            // Mark current node as visited
            visited[u] = true;

            // If destination is reached, return its shortest distance
            if (u == dest) {
                return dist[dest];
            }

            // Traverse all adjacent nodes
            for (int[] edge : adj.getOrDefault(u, new ArrayList<>())) {

                int v = edge[0]; // Adjacent node
                int d = edge[1]; // Edge weight

                // Process only if neighbor is not visited
                if (!visited[v]) {

                    // Relaxation Step
                    // If a shorter path is found, update the distance
                    if (wt + d < dist[v]) {

                        dist[v] = wt + d;

                        // Push updated distance into the priority queue
                        pq.offer(new int[]{dist[v], v});
                    }
                }
            }
        }

        // If destination is unreachable, return -1
        return dist[dest] == Integer.MAX_VALUE ? -1 : dist[dest];
    }

    // Function to build the graph and find the shortest path
    public int shortestPath(int V, int src, int dest, List<List<Integer>> edges) {

        // Adjacency List
        // node -> {neighbor, weight}
        HashMap<Integer, ArrayList<int[]>> adj = new HashMap<>();

        // Build an undirected weighted graph
        for (List<Integer> edge : edges) {

            int u = edge.get(0);
            int v = edge.get(1);
            int w = edge.get(2);

            adj.putIfAbsent(u, new ArrayList<>());
            adj.putIfAbsent(v, new ArrayList<>());

            adj.get(u).add(new int[]{v, w});
            adj.get(v).add(new int[]{u, w});
        }

        // Distance array
        // Initially every node is unreachable
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);

        // Visited array
        boolean[] visited = new boolean[V];

        // Run Dijkstra's Algorithm
        return dijkstra(src, dest, adj, dist, visited);
    }
}