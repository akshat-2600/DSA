/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach-1 (Using DFS for each query) - TLE
// T.C : O(q * (V+E)), q = number of queries, V+E for DFS
// S.C : O(V+E)


class Solution {
public:
    bool dfs(int curr, int target, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {

        if (curr == target) {
            return true;
        }

        visited[curr] = true;

        for (int& v : adj[curr]) {
            if (!visited[v]) {
                if (dfs(v, target, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>> adj;
        
        for (int i=1; i < n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                adj[i].push_back(i-1);
                adj[i-1].push_back(i);
            }
        }

        vector<bool> result;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            vector<bool> visited(n, false);
            result.push_back(dfs(u, v, adj, visited));
        }
        return result;
    }
};


//Approach-2 (Using Disjoint Set Union - DSU) - Accepted
//T.C : O(N + Q * α(N)), N = length of nums, Q = number of queries, α = Inverse Ackermann function
//S.C : O(N), for parent and rank arrays in DSU

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int new_x = find(x);
        int new_y = find(y);

        if (new_x == new_y) {
            return;
        }

        if (rank[new_x] < rank[new_y]) {
            parent[new_x] = new_y;

        } else if (rank[new_y] > rank[new_x]) {
            parent[new_x] = new_y;

        } else {

            parent[new_y] = new_x;
            rank[new_x]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        parent.resize(n);
        rank.assign(n, 0);

        for (int i=0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                Union(i, i-1);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (find(u) == find(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};


// Approach-3 (Using DFS once and then mark component)
// T.C : O(q + (V+E))
// S.C : O(V+E)

class Solution {
public:
    void dfs(int curr, int compId, unordered_map<int, vector<int>>& adj, vector<int>& component) {
        component[curr] = compId;

        for (int &ngbr : adj[curr]) {
            if (component[ngbr] == -1) {
                dfs(ngbr, compId, adj, component);
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i=1; i < n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                adj[i].push_back(i-1);
                adj[i-1].push_back(i);
            }
        }

        vector<int> component(n, -1);
        int compId = 0;

        for (int i=0; i < n; i++) {
            if (component[i] == -1) {
                dfs(i, compId, adj, component);
                compId++;
            }
        }

        vector<bool> result;
        for (auto& query: queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};


// Approach-4 (Simple Observation - assign components)
// T.C : O(n+q)
// S.C : O(n)


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;

        for (int i=1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                compId++;
            }
            component[i] = compId;
        }        

        vector<bool> result;
        for (auto& q: queries) {
            result.push_back(component[q[0]] == component[q[1]]);
        }
        
        return result;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach-1 (Using DFS for each query) - TLE
// T.C : O(q * (V+E)), q = number of queries, V+E for DFS
// S.C : O(V+E)

class Solution {

    private boolean dfs(int curr, int target, List<Integer>[] adj, boolean[] visited) {

        if (curr == target)
            return true;

        visited[curr] = true;

        for (int next : adj[curr]) {
            if (!visited[next]) {
                if (dfs(next, target, adj, visited))
                    return true;
            }
        }

        return false;
    }

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        List<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                adj[i].add(i - 1);
                adj[i - 1].add(i);
            }
        }

        boolean[] ans = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {

            boolean[] visited = new boolean[n];

            ans[i] = dfs(queries[i][0], queries[i][1], adj, visited);
        }

        return ans;
    }
}


//Approach-2 (Using Disjoint Set Union - DSU) - Accepted
//T.C : O(N + Q * α(N)), N = length of nums, Q = number of queries, α = Inverse Ackermann function
//S.C : O(N), for parent and rank arrays in DSU


class Solution {

    int[] parent;
    int[] rank;

    private int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    private void union(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] <= maxDiff) {
                union(i, i - 1);
            }
        }

        boolean[] ans = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {

            ans[i] = find(queries[i][0]) == find(queries[i][1]);
        }

        return ans;
    }
}


// Approach-3 (Using DFS once and then mark component)
// T.C : O(q + (V+E))
// S.C : O(V+E)


import java.util.*;

class Solution {

    private void dfs(int node, int compId, List<Integer>[] adj, int[] component) {

        component[node] = compId;

        for (int next : adj[node]) {

            if (component[next] == -1) {
                dfs(next, compId, adj, component);
            }
        }
    }

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        List<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] <= maxDiff) {

                adj[i].add(i - 1);
                adj[i - 1].add(i);
            }
        }

        int[] component = new int[n];
        Arrays.fill(component, -1);

        int compId = 0;

        for (int i = 0; i < n; i++) {

            if (component[i] == -1) {

                dfs(i, compId, adj, component);
                compId++;
            }
        }

        boolean[] ans = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {

            ans[i] = component[queries[i][0]] == component[queries[i][1]];
        }

        return ans;
    }
}


// Approach-4 (Simple Observation - assign components)
// T.C : O(n+q)
// S.C : O(n)

class Solution {

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        int[] component = new int[n];

        int compId = 0;
        component[0] = compId;

        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] > maxDiff)
                compId++;

            component[i] = compId;
        }

        boolean[] ans = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {

            ans[i] = component[queries[i][0]] == component[queries[i][1]];
        }

        return ans;
    }
}