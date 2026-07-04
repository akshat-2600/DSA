/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
*/


/******************************************************************** C++ ********************************************************************/

// DFS
//T.C : O(V + E)
//S.C : O(V + E)


class Solution {
public:
    void DFS(int u, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool>& visited, int &result) {
        visited[u] = true;

        for (auto& vec : adj[u]) {
            int v = vec.first;
            int d = vec.second;

            result = min(result, d);

            if (!visited[v]) {
                DFS(v, adj, visited, result);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        int result = INT_MAX;
        vector<bool> visited(n, false);
        DFS(1, adj, visited, result);

        return result;
    }
};


// BFS
//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
public:
    void BFS(int u, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool>& visited, int &result) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            for (auto &P: adj[curr]) {
                int v = P.first;
                int d = P.second;

                result = min(result, d);
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& road: roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        int result = INT_MAX;
        vector<bool> visited(n, false);
        
        BFS(1, adj, visited, result);

        return result;
        
    }
};



/******************************************************************** JAVA ********************************************************************/


// DFS

// T.C : O(V + E)
// S.C : O(V + E)

class Solution {
    
    public void DFS(int u, HashMap<Integer, ArrayList<int[]>> adj, boolean[] visited, int[] result) {

        visited[u] = true;

        for (int[] vec : adj.get(u)) {

            int v = vec[0];
            int d = vec[1];

            result[0] = Math.min(result[0], d);

            if (!visited[v]) {
                DFS(v, adj, visited, result);
            }
        }
    }

    public int minScore(int n, int[][] roads) {
        
        HashMap<Integer, ArrayList<int[]>> adj = new HashMap<>();

        for (int i=1; i <= n; i++) {
            adj.put(i, new ArrayList<>());
        }

        for (int[] road : roads) {

            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj.get(u).add(new int[]{v, d});
            adj.get(v).add(new int[]{u, d});
        }

        int[] result = {Integer.MAX_VALUE};
        boolean[] visited = new boolean[n+1];

        DFS(1, adj, visited, result);

        return result[0];

    }
}


// BFS 

// T.C : O(V + E)
// S.C : O(V + E)

class Solution {

    public void BFS(int u, HashMap<Integer, ArrayList<int[]>> adj, boolean[] visited, int[] result) {

        Queue<Integer> q = new LinkedList<>();

        q.offer(u);
        visited[u] = true;

        while (!q.isEmpty()) {

            int curr = q.poll();

            for (int[] p : adj.get(curr)) {

                int v = p[0];
                int d = p[1];

                result[0] = Math.min(result[0], d);

                if (!visited[v]) {
                    visited[v] = true;
                    q.offer(v);
                }
            }
        }
    }

    public int minScore(int n, int[][] roads) {
        
        HashMap<Integer, ArrayList<int[]>> adj = new HashMap<>();

        for (int i=1; i <= n; i++) {
            adj.put(i, new ArrayList<>());
        }

        for (int[] road: roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj.get(u).add(new int[]{v, d});
            adj.get(v).add(new int[]{u, d});
        }

        int[] result = {Integer.MAX_VALUE};
        boolean[] visited = new boolean[n+1];

        BFS(1, adj, visited, result);

        return result[0];
    }
}