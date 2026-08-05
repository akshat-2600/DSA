/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/remove-methods-from-project/description/
*/

/************************************************************ C++ ************************************************************************/

//T.C : O(V + E)
//S.C : O(V + E)

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // adjacency list
        vector<vector<int>> adj(n);  // u -> (ngbr1, ngbr2)
        vector<int> inDegree(n);
        vector<bool> suspicious(n, false);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // BFS
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int &ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if (!suspicious[ngbr]) {
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        if (cannotRemove) {
            vector<int> vec(n);
            for (int i = 0; i < n; i++) {
                vec[i] = i;
            }      
            return vec;
        }
        return result;
    }
};

/************************************************************ JAVA ************************************************************************/

