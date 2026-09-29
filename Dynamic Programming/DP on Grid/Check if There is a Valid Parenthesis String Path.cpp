/*
    Company Tags    :    
    LeetCode Link   :   https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/

*/


/******************************************************** C++ ********************************************************/

// Approach 1       : Pure Recursion
// Time Complexity  : O(2^(m+n))
// Space Complexity : O(m+n)

class Solution {
public:
    int m, n;

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool check(int i, int j, vector<vector<char>>& grid, int open) {
        if (grid[i][j] == '(') {
            open++;
        } else {
            open--;
            if (open < 0) return false;
        }
        
        if (i == m-1 && j == n-1) {
            if (open == 0) {
                return true;
            } else {
                return false;
            }
        }

        bool right = false;
        bool down  = false;

        // Right
        if (isValid(i, j+1)) {
            right = check(i, j+1, grid, open);
        }
        // Downn
        if (isValid(i+1, j)) {
            down = check(i+1, j, grid, open);
        }

        return right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (m == 1 && n == 1) {
            return false;
        }

        return check(0, 0, grid, 0);
    }
};


// Approach 2       : Recursion + Memoization
// Time Complexity  : O(m * n * (m + n))
// Space Complexity : O(m * n * (m + n))

class Solution {
public:
    int m, n;

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool check(int i, int j, vector<vector<char>>& grid,
               int open, vector<vector<vector<int>>>& dp) {

        // Update parentheses balance
        if (grid[i][j] == '(') {
            open++;
        } else {
            open--;

            // Invalid prefix
            if (open < 0) return false;
        }

        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return open == 0;
        }

        // Return previously computed result
        if (dp[i][j][open] != -1) {
            return dp[i][j][open];
        }

        bool right = false;
        bool down = false;

        // Move right
        if (isValid(i, j + 1)) {
            right = check(i, j + 1, grid, open, dp);
        }

        // Move down
        if (isValid(i + 1, j)) {
            down = check(i + 1, j, grid, open, dp);
        }

        // Store the result
        return dp[i][j][open] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n, -1))
        );

        return check(0, 0, grid, 0, dp);
    }
};


// Approach 3       : Bottom Up DP
// Time Complexity  : O(m * n * (m + n))
// Space Complexity : O(m * n * (m + n))

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][open] stores whether a valid path exists
        // from (i,j) to the destination with the given incoming balance.

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Traverse the grid backward
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {

                for (int open = 0; open < m + n; ++open) {

                    int next_open = open;

                    // Process current character
                    if (grid[i][j] == '(') {
                        next_open++;
                    } else {
                        next_open--;
                    }

                    // Invalid balance
                    if (next_open < 0 || next_open >= m + n) {
                        dp[i][j][open] = false;
                        continue;
                    }

                    // Destination condition
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][open] = (next_open == 0);
                        continue;
                    }

                    bool right = false;
                    bool down = false;

                    // Move right
                    if (j + 1 < n) {
                        right = dp[i][j + 1][next_open];
                    }

                    // Move down
                    if (i + 1 < m) {
                        down = dp[i + 1][j][next_open];
                    }

                    // Either direction can lead to a valid path
                    dp[i][j][open] = right || down;
                }
            }
        }

        // Start at (0,0) with an initial balance of 0
        return dp[0][0][0];
    }
};