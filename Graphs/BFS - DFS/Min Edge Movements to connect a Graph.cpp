/*
    Company Tags             : 
    GeeksForGeeks Link       :   https://www.geeksforgeeks.org/problems/connecting-the-graph/1


/************************************************************ C++ ************************************************************************/

// Approach : Using DFS
//T.C : O(n + m)
//S.C : O(n + m)


class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis);
            }
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        // At least n-1 edges are required
        if (m < n - 1)
            return -1;

        // Create adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int components = 0;

        // Count connected components
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                components++;

                dfs(i, adj, vis);
            }
        }

        // To connect k components, k-1 edges are required
        return components - 1;
    }
};


// Approach : Using BFS
//T.C : O(n + m)
//S.C : O(n + m)


class Solution {
public:

    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {

        queue<int> q;

        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {

                if (!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        // Need at least n-1 edges to connect n vertices
        if (m < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        // Build graph
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int components = 0;

        // Count connected components using BFS
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                components++;

                bfs(i, adj, vis);
            }
        }

        return components - 1;
    }
};


// Approach : Using DSU
//T.C : O((n + m) * alpha(n))
//S.C : O(n)

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
        else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
};



class Solution {
public:

    int minEdgesReq(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        int extra = 0;

        // Find redundant/extra edges
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u) == dsu.find(v)) {
                // Already connected -> this edge is extra
                extra++;
            }
            else {
                dsu.Union(u, v);
            }
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                components++;
            }
        }

        // Need components - 1 edges to connect all components
        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};



/************************************************************ JAVA ************************************************************************/

