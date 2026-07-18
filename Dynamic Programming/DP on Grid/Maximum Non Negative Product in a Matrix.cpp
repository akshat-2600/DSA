/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/
*/


/************************************************************ C++ ************************************************************/

// Approach 1: Pure recursion
// T.C : O(2 ^ (m+n))
// S.C : O(m+n) 

class Solution {
public:
    int m, n;
    typedef long long ll;
    typedef pair<ll, ll> ppl;
    int MOD = 1e9 + 7;

    ppl solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // Down
        if (i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);

            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});

            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        // Right
        if (j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);

            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});

            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        auto [maxProd, minProd] =  solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n) 

class Solution {
public:
    int m, n;
    typedef long long ll;
    typedef pair<ll, ll> ppl;
    int MOD = 1e9 + 7;

    vector<vector<ppl>> t;

    ppl solve(int i, int j, vector<vector<int>> &grid) {
        if (i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        // Down
        if (i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);

            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});

            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        // Right
        if (j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);

            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});

            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] =  {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        t = vector<vector<ppl>>(m, vector<ppl>(n, {LLONG_MIN, LLONG_MAX}));

        auto [maxProd, minProd] = solve(0, 0, grid);
        
        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


// Approach 3: Bottom up
// T.C : O(m * n)
// S.C : O(m * n) 

class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> ppl;
    int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        // bottom up dp
        vector<vector<ppl>> t(m, vector<ppl>(n));
        // t[i][j] = {maxVal, minVal} to reach from (0,0) to (i, j)

        t[0][0] = {grid[0][0], grid[0][0]};

        // filling the first row
        for (int j=1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first * grid[0][j]; // maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; // minVal
        }

        // filling the first col
        for (int i=1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first * grid[i][0]; // maxVal
            t[i][0].second = t[i-1][0].second * grid[i][0]; // minVal
        }

        // fill dp table
        for (int i=1; i < m; i++) {
            for (int j=1; j < n; j++) {

                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;
                
                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                
                t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


/************************************************************ JAVA ************************************************************/


// Approach 1: Pure recursion
// T.C : O(2 ^ (m+n))
// S.C : O(m+n) 

class Solution {

    int m, n;
    final int MOD = 1_000_000_007;

    class Pair {
        long maxProd;
        long minProd;

        Pair(long maxProd, long minProd) {
            this.maxProd = maxProd;
            this.minProd = minProd;
        }
    }

    private Pair solve(int i, int j, int[][] grid) {

        // Destination
        if (i == m - 1 && j == n - 1) {
            return new Pair(grid[i][j], grid[i][j]);
        }

        long maxVal = Long.MIN_VALUE;
        long minVal = Long.MAX_VALUE;

        // Move Down
        if (i + 1 < m) {
            Pair down = solve(i + 1, j, grid);

            maxVal = Math.max(maxVal,
                    Math.max((long) grid[i][j] * down.maxProd,
                             (long) grid[i][j] * down.minProd));

            minVal = Math.min(minVal,
                    Math.min((long) grid[i][j] * down.maxProd,
                             (long) grid[i][j] * down.minProd));
        }

        // Move Right
        if (j + 1 < n) {
            Pair right = solve(i, j + 1, grid);

            maxVal = Math.max(maxVal,
                    Math.max((long) grid[i][j] * right.maxProd,
                             (long) grid[i][j] * right.minProd));

            minVal = Math.min(minVal,
                    Math.min((long) grid[i][j] * right.maxProd,
                             (long) grid[i][j] * right.minProd));
        }

        return new Pair(maxVal, minVal);
    }

    public int maxProductPath(int[][] grid) {

        m = grid.length;
        n = grid[0].length;

        Pair ans = solve(0, 0, grid);

        return ans.maxProd < 0 ? -1 : (int) (ans.maxProd % MOD);
    }
}


// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n) 

class Solution {

    int m, n;
    final int MOD = 1_000_000_007;

    class Pair {
        long maxProd;
        long minProd;

        Pair(long maxProd, long minProd) {
            this.maxProd = maxProd;
            this.minProd = minProd;
        }
    }

    Pair[][] dp;

    private Pair solve(int i, int j, int[][] grid) {

        // Destination
        if (i == m - 1 && j == n - 1) {
            return new Pair(grid[i][j], grid[i][j]);
        }

        if (dp[i][j] != null) {
            return dp[i][j];
        }

        long maxVal = Long.MIN_VALUE;
        long minVal = Long.MAX_VALUE;

        // Down
        if (i + 1 < m) {
            Pair down = solve(i + 1, j, grid);

            maxVal = Math.max(maxVal,
                    Math.max((long) grid[i][j] * down.maxProd,
                             (long) grid[i][j] * down.minProd));

            minVal = Math.min(minVal,
                    Math.min((long) grid[i][j] * down.maxProd,
                             (long) grid[i][j] * down.minProd));
        }

        // Right
        if (j + 1 < n) {
            Pair right = solve(i, j + 1, grid);

            maxVal = Math.max(maxVal,
                    Math.max((long) grid[i][j] * right.maxProd,
                             (long) grid[i][j] * right.minProd));

            minVal = Math.min(minVal,
                    Math.min((long) grid[i][j] * right.maxProd,
                             (long) grid[i][j] * right.minProd));
        }

        dp[i][j] = new Pair(maxVal, minVal);
        return dp[i][j];
    }

    public int maxProductPath(int[][] grid) {

        m = grid.length;
        n = grid[0].length;

        dp = new Pair[m][n];

        Pair ans = solve(0, 0, grid);

        return ans.maxProd < 0 ? -1 : (int) (ans.maxProd % MOD);
    }
}


// Approach 3: Bottom up
// T.C : O(m * n)
// S.C : O(m * n) 

class Solution {

    final int MOD = 1_000_000_007;

    class Pair {
        long maxProd;
        long minProd;

        Pair(long maxProd, long minProd) {
            this.maxProd = maxProd;
            this.minProd = minProd;
        }
    }

    public int maxProductPath(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        Pair[][] dp = new Pair[m][n];

        // Initialize all cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = new Pair(0, 0);
            }
        }

        dp[0][0] = new Pair(grid[0][0], grid[0][0]);

        // Fill first row
        for (int j = 1; j < n; j++) {
            dp[0][j].maxProd = dp[0][j - 1].maxProd * grid[0][j];
            dp[0][j].minProd = dp[0][j - 1].minProd * grid[0][j];
        }

        // Fill first column
        for (int i = 1; i < m; i++) {
            dp[i][0].maxProd = dp[i - 1][0].maxProd * grid[i][0];
            dp[i][0].minProd = dp[i - 1][0].minProd * grid[i][0];
        }

        // Fill remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                long upMax = dp[i - 1][j].maxProd;
                long upMin = dp[i - 1][j].minProd;

                long leftMax = dp[i][j - 1].maxProd;
                long leftMin = dp[i][j - 1].minProd;

                long a = upMax * grid[i][j];
                long b = upMin * grid[i][j];
                long c = leftMax * grid[i][j];
                long d = leftMin * grid[i][j];

                dp[i][j].maxProd = Math.max(Math.max(a, b), Math.max(c, d));
                dp[i][j].minProd = Math.min(Math.min(a, b), Math.min(c, d));
            }
        }

        long maxProd = dp[m - 1][n - 1].maxProd;

        return maxProd < 0 ? -1 : (int) (maxProd % MOD);
    }
}