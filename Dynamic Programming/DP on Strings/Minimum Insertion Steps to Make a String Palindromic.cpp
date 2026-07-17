/*
    Company Tags                : Google, Amazon, Microsoft, Airtel
    Leetcode Link               : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/


/************************************************************ C++ ************************************************************/

// Approach : Pure Recursion
// T.C : O(2^N)
// S.C : O(N)

class Solution {
public:
    int n;

    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (s[i] == s[j]) {
            return solve(s, i+1, j-1);
        } else {
            return 1 + min(solve(s, i, j-1), solve(s, i+1, j));
        }
    }

    int minInsertions(string s) {
        n = s.length();

        return solve(s, 0, n-1);
    }
};

// Approach : Recursion + Memoization
// T.C : O(N^2)
// S.C : O(N^2)

class Solution {
public:
    int n;
    int t[501][501];

    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i+1, j-1);
        } else {
            return t[i][j] = 1 + min(solve(s, i, j-1), solve(s, i+1, j));
        }
    }

    int minInsertions(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));

        return solve(s, 0, n-1);
    }
};

// Approach : Bottom up
// T.C : O(N^2)
// S.C : O(N^2)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int L=2; L <= n; L++) {
            for (int i=0; i+L-1 < n; i++) {
                int j = i+L-1;

                if (s[i] == s[j]) {
                    t[i][j] = t[i+1][j-1];
                } else {
                    t[i][j] = 1+min(t[i+1][j], t[i][j-1]);
                }
            }
        }

        return t[0][n-1];
    }
};


/************************************************************ JAVA ************************************************************/

// Approach : Pure Recursion
// T.C : O(2^N)
// S.C : O(N)

class Solution {
    public int minInsertions(String s) {
        return solve(s, 0, s.length() - 1);
    }

    private int solve(String s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (s.charAt(i) == s.charAt(j)) {
            return solve(s, i + 1, j - 1);
        }

        return 1 + Math.min(solve(s, i, j - 1),
                            solve(s, i + 1, j));
    }
}

// Approach : Recursion + Memoization
// T.C : O(N^2)
// S.C : O(N^2)

class Solution {
    private int[][] dp;

    public int minInsertions(String s) {
        int n = s.length();
        dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            java.util.Arrays.fill(dp[i], -1);
        }

        return solve(s, 0, n - 1);
    }

    private int solve(String s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s.charAt(i) == s.charAt(j)) {
            dp[i][j] = solve(s, i + 1, j - 1);
        } else {
            dp[i][j] = 1 + Math.min(solve(s, i, j - 1),
                                    solve(s, i + 1, j));
        }

        return dp[i][j];
    }
}

// Approach : Bottom up
// T.C : O(N^2)
// S.C : O(N^2)

class Solution {
    public int minInsertions(String s) {
        int n = s.length();

        int[][] dp = new int[n][n];

        for (int L=2; L <= n; L++) {
            for (int i=0; i+L-1 < n; i++) {
                int j = i + L - 1;

                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n-1];
    }
}