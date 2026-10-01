/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/course-schedule-ii/

*/    

/******************************************************** C++ ********************************************************/

// Approach : Topological Sort + BFS
// T.C      : O(V + E)
// S.C      : O(V + E)

class Solution {
public:
    int n;

    bool topologicalCheck(unordered_map<int, vector<int>> &adj, vector<int>& indegree, vector<int> &ans) {
        queue<int> q;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                    count++;
                    ans.push_back(v);
                }
            }
        }
        return count == n;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (auto &preq : prerequisites) {
            int a = preq[0];
            int b = preq[1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        
        vector<int> ans;

        if (topologicalCheck(adj, indegree, ans)) {
            return ans;
        }
        return {};
    }
};

// Approach : Topological Sort + DFS
// T.C      : O(V + E)
// S.C      : O(V + E)

class Solution {
public:
    bool hasCycle;

    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {
            if (inRecursion[v]) {
                hasCycle = true;
                return;
            }

            if (!visited[v]) {
                DFS(adj, v, visited, st, inRecursion);
            }
        }
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;

        stack<int> st;

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, st, inRecursion);
            }
        }

        vector<int> result;

        if (hasCycle) {
            return {};
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};