/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/network-recovery-pathways
*/

/************************************************************ C++ ************************************************************************/

// T.C : O(E + log(Max) * E*log(V))
// S.C : O(V + E)

class Solution {
public:
    typedef long long ll;

    bool check(int mid, vector<vector<pair<int, int>>> &adj, vector<bool>& online, ll k, int n) {
        const ll INF = 4e18;

        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) {
                continue;
            }

            if (u == n-1) {
                return d <= k;
            }

            for (auto& [v, w] : adj[u]) {
                if (w < mid) {
                    continue;
                }

                if (v != n-1 && online[v] == false) {
                    continue;
                }

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);

        int mx = 0;

        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];

            adj[u].push_back({v, c});
            mx = max(mx, c);
        }

        int left = 0;
        int right = mx;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left)/2;

            if (check(mid, adj, online, k, n)) {
                ans = mid;
                left = mid+1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};




/************************************************************ JAVA ************************************************************************/


class Solution {

    class Pair {
        int node;
        long dist;

        Pair(int node, long dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    boolean check(int mid, List<int[]>[] adj, boolean[] online, long k, int n) {
        long INF = Long.MAX_VALUE;

        long[] dist = new long[n];
        Arrays.fill(dist, INF);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> Long.compare(a.dist, b.dist));

        dist[0] = 0;
        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();

            long d = cur.dist;
            int u  = cur.node;

            if (d != dist[u]) {
                continue;
            }

            if (u == n-1) {
                return d <= k; 
            }

            for (int[] edge: adj[u]) {
                int v = edge[0];
                int w = edge[1];

                if (w < mid) {
                    continue;
                }

                if (v != n-1 && !online[v]) {
                    continue;
                }

                if (dist[v] > d+w) {
                    dist[v] = d+w;
                    pq.offer(new Pair(v, dist[v]));
                }
            }
        }
        return false;
    }

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int n = online.length;

        List<int[]>[] adj = new ArrayList[n];

        for (int i=0; i<n; i++) {
            adj[i] = new ArrayList<>();
        }

        int maxWeight = 0;

        for (int[] edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];

            adj[u].add(new int[]{v, c});
            maxWeight = Math.max(maxWeight, c);
        }

        int low = 0;
        int high = maxWeight;

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (check(mid, adj, online, k, n)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid -1;
            }
        }
        return ans;
    }
}