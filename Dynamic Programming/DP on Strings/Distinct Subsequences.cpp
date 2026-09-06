/*
    Company Tags    :   SWIGGY
    Leetcode Link   :   https://leetcode.com/problems/distinct-subsequences/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Pure Recursion
// T.C        : O(2^ns)
// S.C        : O(ns)   (recursion call stack)

class Solution {
public:
    int n;

    int solve(int i, int j, string& s, string& t) {
        if (i == n) {
            if (j == t.length()) {
                return 1;
            }
            return 0;
        }
        
        int take  = 0;
        int skip1 = 0;
        int skip2 = 0;

        if (s[i] == t[j]) {
            take  = solve(i+1, j+1, s, t);  // take
            skip2 = solve(i+1, j, s, t);    // skip although equal
        } else {
            skip1 = solve(i+1, j, s, t);    // skip
        }
        return take + skip1 + skip2;
    }

    int numDistinct(string s, string t) {
        n = s.length();
        int i = 0;
        int j = 0;

        return solve(i, j, s, t);
    }
};


// Approach-2 : Recursion + Memoization
// T.C        : O(ns * nt)
// S.C        : o(ns * nt)  + O(ns) -> (recursion call stack) 

class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int i, int j, string& s, string& t) {
        if (i == n) {
            if (j == t.length()) {
                return 1;
            }
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int take  = 0;
        int skip1 = 0;
        int skip2 = 0;

        if (s[i] == t[j]) {
            take  = solve(i+1, j+1, s, t);  
            skip2 = solve(i+1, j, s, t);      
        } else {
            skip1 = solve(i+1, j, s, t);
        }
        return dp[i][j] = take + skip1 + skip2;
    }

    int numDistinct(string s, string t) {
        n = s.length();
        int i = 0;
        int j = 0;
        memset(dp, -1, sizeof(dp));

        return solve(i, j, s, t);
    }
};

// Approach-3 : Bottom Up
// T.C        : O(ns * nt)
// S.C        : O(ns * nt)

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        vector<vector<unsigned int>> dp(ns+1, vector<unsigned int>(nt+1, 0));

        // Base case
        for (int i = 0; i <= ns; i++) {
            dp[i][nt] = 1;
        }

        for (int i = ns-1; i >= 0; i--) {
            for (int j = nt-1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return (int)dp[0][0];
    }
};

// Approach-4 : Bottom Up Space Optimized
// T.C        : O(ns * nt)
// S.C        : O(nt)

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        vector<unsigned int> curr(nt+1, 0);

        // Base case
        curr[nt] = 1;

        vector<unsigned int> prev = curr;

        for (int i = ns-1; i >= 0; i--) {
            for (int j = nt-1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    prev[j] = curr[j+1] + curr[j];
                } else {
                    prev[j] = curr[j];
                }
            }
            curr = prev;
        }
        return (int)curr[0];
    }
};

/******************************************************** JAVA ********************************************************/

//coming soon