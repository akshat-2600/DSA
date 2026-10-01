/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/course-schedule/

*/    

/******************************************************** C++ ********************************************************/

// Approach : Topological Sort + BFS
// T.C      : O(V + E)
// S.C      : O(V + E)

class Solution {
public:
    int n;

    bool topologicalCheck(unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        int count = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        // Adjacency matrix
        unordered_map<int, vector<int>> adj;
        // Indegree
        vector<int> indegree(n, 0);

        for (auto& preq : prerequisites) {
            int a = preq[0];
            int b = preq[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalCheck(adj, indegree);
    }
};


// Approach : Topological Sort + DFS
// T.C      : O(V + E)
// S.C      : O(V + E)

class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion)) {
                return false;
            }
        }
        return true;
    }
};