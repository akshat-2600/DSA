/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/minimum-path-sum/
*/


/************************************************************ C++ ************************************************************/

// Approach 1: Pure Recursion
// T.C : O(2 ^ (m + n))
// S.C : O(m + n)  recursion stack

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return INT_MAX;
        }

        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(0, 0, m, n, grid);
    }
};

// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n)

class Solution {
public:
    int t[201][201];

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return INT_MAX;
        }

        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return t[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t, -1, sizeof(t));

        return solve(0, 0, m, n, grid);
    }
};

// Approach 3: Bottom Up
// T.C : O(m * n)
// S.C : O(m * n)


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        t[0][0] = grid[0][0];

        // fill 1st row
        for (int row=1; row < m; row++) {
            t[row][0] = t[row-1][0] + grid[row][0];
        }

        // fill 1st col
        for (int col=1; col < n; col++) {
            t[0][col] = t[0][col-1] + grid[0][col];
        }

        // fill dp table
        for (int i=1; i < m; i++) {
            for (int j=1; j < n; j++) {

                int right = t[i][j-1];
                int down  = t[i-1][j];

                t[i][j] = grid[i][j] + min(right, down);
            }
        }

        return t[m-1][n-1];
    }
};


/************************************************************ JAVA ************************************************************/


// Approach 1: Pure Recursion
// T.C : O(2 ^ (m + n))
// S.C : O(m + n)  recursion stack

class Solution {
    private int solve(int i, int j, int m, int n, int[][] grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return Integer.MAX_VALUE;
        }

        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return grid[i][j] + Math.min(right, down);
    }

    public int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;

        return solve(0, 0, m, n, grid);
    }
}

// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n)


class Solution {
    private int[][] dp;

    private int solve(int i, int j, int m, int n, int[][] grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return Integer.MAX_VALUE;
        }

        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return dp[i][j] = grid[i][j] + Math.min(right, down);
    }

    public int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;

        dp = new int[m][n];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, m, n, grid);
    }
}

// Approach 3: Bottom up
// T.C : O(m * n)
// S.C : O(m * n)

class Solution {
    public int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m][n];

        dp[0][0] = grid[0][0];

        // fill first column
        for (int row = 1; row < m; row++) {
            dp[row][0] = dp[row-1][0] + grid[row][0];
        }

        // fill first row
        for (int col = 1; col < n; col++) {
            dp[0][col] = dp[0][col-1] + grid[0][col];
        }

        // fill remaining cells
        for (int i=1; i < m; i++) {
            for (int j=1; j < n; j++) {

                int left = dp[i][j-1];
                int up = dp[i-1][j];

                dp[i][j] = grid[i][j] + Math.min(left, up);
            }
        }

        return dp[m-1][n-1];
    }
}

