/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/edit-distance/description/
*/

/************************************************************** C++ **************************************************************/
//T.C : O(3^n)
//S.C : O(1)

// Recursion

class Solution {
public:
    int m;
    int n;

    int solve(string& s1, string& s2, int i, int j) {
        if (i >= m) {
            return n - j;
        } else if (j >= n) {
            return m - i;
        }

        if (s1[i] == s2[j]) {
            return solve(s1, s2, i+1, j+1);
        } else {
            int deleteC = 1 + solve(s1, s2, i+1, j);
            int insertC = 1 + solve(s1, s2, i, j+1);
            int replaceC = 1 + solve(s1, s2, i+1, j+1);

            return min({deleteC, insertC, replaceC});
        }
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        return solve(s1, s2, 0, 0);
    }
};

// Recursion + Memoization (index based)

class Solution {
public:
    int m;
    int n;
    int t[501][501];

    int solve(string& s1, string& s2, int i, int j) {
        if (i >= m) {
            return n - j;
        } else if (j >= n) {
            return m - i;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s1[i] == s2[j]) {
            return t[i][j] = solve(s1, s2, i+1, j+1);
        } else {
            int deleteC = 1 + solve(s1, s2, i+1, j);
            int insertC = 1 + solve(s1, s2, i, j+1);
            int replaceC = 1 + solve(s1, s2, i+1, j+1);

            return t[i][j] = min({deleteC, insertC, replaceC});
        }
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        memset(t, -1, sizeof(t));

        return solve(s1, s2, 0, 0);
    }
};


// Recursion + Memoization (Length based)

class Solution {
public:
    int m;
    int n;
    int t[501][501];

    int solve(string& s1, string& s2, int m, int n) {
        if (m == 0) {
            return n;
        } else if (n == 0) {
            return m;
        }

        if (t[m][n] != -1) {
            return t[m][n];
        }

        if (s1[m-1] == s2[n-1]) {
            return t[m][n] = solve(s1, s2, m-1, n-1);
        } else {
            int deleteC = 1 + solve(s1, s2, m-1, n);
            int insertC = 1 + solve(s1, s2, m, n-1);
            int replaceC = 1 + solve(s1, s2, m-1, n-1);

            return t[m][n] = min({deleteC, insertC, replaceC});
        }
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        memset(t, -1, sizeof(t));

        return solve(s1, s2, m, n);
    }
};


// Bottom up 
// T.C : O(m * n)
// S.C : O(m * n)

class Solution {
public:

    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1));

        for (int i=0; i < m+1; i++) {
            for (int j=0; j < n+1; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = i + j;
                } else if (s1[i-1] == s2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                } else {
                    int deleteC = 1 + t[i-1][j];
                    int insertC = 1 + t[i][j-1];
                    int replaceC = 1 + t[i-1][j-1];

                    t[i][j] = min({deleteC, insertC, replaceC});
                }
            }
        }
        return t[m][n];
    }
};

/************************************************************** JAVA ***************************************************************/

// T.C : O(3^n)
// S.C : O(1)

// Recursion

class Solution {

    int m, n;

    public int solve(String s1, String s2, int i, int j) {

        if (i >= m) {
            return n - j;
        } else if (j >= n) {
            return m - i;
        }

        if (s1.charAt(i) == s2.charAt(j)) {
            return solve(s1, s2, i + 1, j + 1);
        } else {

            int deleteC = 1 + solve(s1, s2, i + 1, j);
            int insertC = 1 + solve(s1, s2, i, j + 1);
            int replaceC = 1 + solve(s1, s2, i + 1, j + 1);

            return Math.min(deleteC, Math.min(insertC, replaceC));
        }
    }

    public int minDistance(String s1, String s2) {

        m = s1.length();
        n = s2.length();

        return solve(s1, s2, 0, 0);
    }
}

// Recursion + Memoization (Index based)

// T.C : O(m * n)
// S.C : O(m * n)

class Solution {

    int m, n;
    int[][] dp = new int[501][501];

    public int solve(String s1, String s2, int i, int j) {

        if (i >= m) {
            return n - j;
        } else if (j >= n) {
            return m - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        } else {

            int deleteC = 1 + solve(s1, s2, i + 1, j);
            int insertC = 1 + solve(s1, s2, i, j + 1);
            int replaceC = 1 + solve(s1, s2, i + 1, j + 1);

            return dp[i][j] = Math.min(deleteC, Math.min(insertC, replaceC));
        }
    }

    public int minDistance(String s1, String s2) {

        m = s1.length();
        n = s2.length();

        for (int i = 0; i <= 500; i++) {
            java.util.Arrays.fill(dp[i], -1);
        }

        return solve(s1, s2, 0, 0);
    }
}


// Recursion + Memoization (Length based)

// T.C : O(m * n)
// S.C : O(m * n)

class Solution {

    int m, n;
    int[][] dp = new int[501][501];

    public int solve(String s1, String s2, int m, int n) {

        if (m == 0) {
            return n;
        } else if (n == 0) {
            return m;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
            return dp[m][n] = solve(s1, s2, m - 1, n - 1);
        } else {

            int deleteC = 1 + solve(s1, s2, m - 1, n);
            int insertC = 1 + solve(s1, s2, m, n - 1);
            int replaceC = 1 + solve(s1, s2, m - 1, n - 1);

            return dp[m][n] = Math.min(deleteC, Math.min(insertC, replaceC));
        }
    }

    public int minDistance(String s1, String s2) {

        m = s1.length();
        n = s2.length();

        for (int i = 0; i <= 500; i++) {
            java.util.Arrays.fill(dp[i], -1);
        }

        return solve(s1, s2, m, n);
    }
}


// Bottom up 

// T.C : O(m * n)
// S.C : O(m * n)

class Solution {

    public int minDistance(String s1, String s2) {

        int m = s1.length();
        int n = s2.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {

            for (int j = 0; j <= n; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {

                    int deleteC = 1 + dp[i - 1][j];
                    int insertC = 1 + dp[i][j - 1];
                    int replaceC = 1 + dp[i - 1][j - 1];

                    dp[i][j] = Math.min(deleteC, Math.min(insertC, replaceC));
                }
            }
        }

        return dp[m][n];
    }
}