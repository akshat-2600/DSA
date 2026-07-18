/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/unique-paths-ii/
*/


/************************************************************ C++ ************************************************************/

// Approach 1: Pure Recursion
// T.C : O(2 ^ (m + n))
// S.C : O(m + n)  recursion stack

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return 0;
        }
        
        if (i == m-1 && j == n-1) {
            return 1;
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(0, 0, m, n, obstacleGrid);
    }
};


// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n)

class Solution {
public:
    int t[101][101];

    int solve(int i, int j, int m, int n, vector<vector<int>> &grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return 0;
        }
        
        if (i == m-1 && j == n-1) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, m, n, obstacleGrid);
    }
};

// Approach 3: Bottom Up
// T.C : O(m * n)
// S.C : O(m * n)


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        // fill first row
        for (int row=0; row < m; row++) {
            if (row >= 1 && grid[row-1][0] == 1) {
                t[row][0] = 0;
                grid[row][0] = 1;

            } else if (grid[row][0] == 1) {
                t[row][0] = 0;
            } else {
                t[row][0] = 1;
            }
        }

        // fill first col
        for (int col=0; col < n; col++) {
            if (col >= 1 && grid[0][col-1] == 1) {
                t[0][col] = 0;
                grid[0][col] = 1;

            } else if (grid[0][col] == 1) {
                t[0][col] = 0;
            } else {
                t[0][col] = 1;
            }
        }

        // Fill dp table
        for (int i=1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (grid[i][j] == 1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
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
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return 0;
        }

        if (i == m-1 && j == n-1) {
            return 1;
        }

        int right = solve(i, j+1, m, n, grid);
        int down  = solve(i+1, j, m, n, grid);

        return right + down;
    }

    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        return solve(0, 0, m, n, grid);
    }
}

// Approach 2: Memoization
// T.C : O(m * n)
// S.C : O(m * n)

import java.util.Arrays;

class Solution {

    private int[][] dp;

    private int solve(int i, int j, int m, int n, int[][] grid) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, m, n, grid);
        int down = solve(i + 1, j, m, n, grid);

        return dp[i][j] = right + down;
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        dp = new int[m][n];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, m, n, obstacleGrid);
    }
}


// Approach 3: Bottom up
// T.C : O(m * n)
// S.C : O(m * n)

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m][n];

        // fill the first column
        for (int row = 0; row < m; row++) {
            if (row >= 1 && grid[row-1][0] == 1) {
                dp[row][0] = 0;
                grid[row][0] = 1;

            } else if (grid[row][0] == 1) {
                dp[row][0] = 0;
        
            } else {
                dp[row][0] = 1;
            }
        }

        // Fill the first row
        for (int col = 0; col < n; col++) {
            if (col >= 1 && grid[0][col-1] == 1) {
                dp[0][col] = 0;
                grid[0][col] = 1;

            } else if (grid[0][col] == 1) {
                dp[0][col] = 0;

            } else {
                dp[0][col] = 1;
            }
        }

        // fill remaining cells
        for (int i=1; i < m; i++) {
            for (int j=1; j < n; j++) {

                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
}