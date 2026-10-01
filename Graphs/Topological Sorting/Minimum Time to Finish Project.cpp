/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/project-manager--141631/1


/******************************************************** C++ ********************************************************/

// T.C   : O(2n)
// S.C   : O()


class Solution {
  public:
    
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        
        int n = duration.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        for (auto &dep : dependencies) {
            int a = dep[0];
            int b = dep[1];
            
            adj[a].push_back(b);
            indegree[b]++;
        }
        
        queue<int> q;
        vector<int> dist = duration;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int &v : adj[u]) {
                dist[v] = max(dist[v], dist[u] + duration[v]);
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        if (count != n) return -1;
        
        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};