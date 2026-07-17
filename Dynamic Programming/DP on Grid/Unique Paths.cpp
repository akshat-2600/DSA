/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/unique-paths/description/
*/


/************************************************************ C++ ************************************************************/

// Approach 1: Pure Recursion
// T.C : O((2^(n+m))
// S.C : O(n+m)

class Solution {
public:
    int M, N;

    int solve(int i, int j) {
        if (i == M-1 && j == N-1) {
            return 1;
        }

        if (i < 0 || i >= M || j < 0 || j >= N) {
            return 0;
        }

        int right = solve(i, j+1);
        int down  = solve(i+1, j);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        return solve(0, 0);
    }
};


// Approach 2: Recursion + Memoization
// T.C : O(n*m)
// S.C : O(n*m)

class Solution {
public:
    int M, N;
    int t[101][101];

    int solve(int i, int j) {
        if (i == M-1 && j == N-1) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (i < 0 || i >= M || j < 0 || j >= N) {
            return t[i][j] = 0;
        }

        int right = solve(i, j+1);
        int down  = solve(i+1, j);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(t, -1, sizeof(t));
        
        return solve(0, 0);
    }
};



// Approach 3: Bottom up
// T.C : O(n*m)
// S.C : O(n*m)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));
        // t[i][j] = total no. of ways to reach [i][j] from [0][0]
        t[0][0] = 1; // total ways to reach 0,0 from 0,0

        // Fill 0th row
        for (int col = 1; col < n; col++) {
            t[0][col] = 1;
        }

        // Fill 0th column
        for (int row = 1; row < m; row++) {
            t[row][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }
        return t[m - 1][n - 1];
    }
};



/************************************************************ JAVA ************************************************************/

// Approach 1: Pure Recursion
// T.C : O((2^(n+m))
// S.C : O(n+m)

class Solution1 {
    private int M, N;

    private int solve(int i, int j) {
        if (i == M - 1 && j == N - 1) {
            return 1;
        }
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return 0;
        }

        int right = solve(i, j + 1);
        int down = solve(i + 1, j);

        return right + down;
    }

    public int uniquePaths(int m, int n) {
        M = m;
        N = n;
        return solve(0, 0);
    }
}



// Approach 2: Recursion + Memoization
// T.C : O(n*m)
// S.C : O(n*m)

import java.util.Arrays;

class Solution2 {
    private int M, N;
    private int[][] t = new int[101][101];

    private int solve(int i, int j) {
        if (i == M - 1 && j == N - 1) {
            return 1;
        }
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j + 1);
        int down = solve(i + 1, j);

        return t[i][j] = right + down;
    }

    public int uniquePaths(int m, int n) {
        M = m;
        N = n;
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(0, 0);
    }
}



// Approach 3: Bottom up
// T.C : O(n*m)
// S.C : O(n*m)

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] t = new int[m][n];

        // Fill the 0th row
        for (int col = 0; col < n; col++) {
            t[0][col] = 1;
        }

        // Fill the 0th column
        for (int row = 0; row < m; row++) {
            t[row][0] = 1;
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }

        return t[m - 1][n - 1];
    }
}
