/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning-ii/
*/


/************************************************************ C++ ************************************************************/

// Approach 1: Pure Recursive
// T.C : O(n * (2^n))
// S.C : O(n)

class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j) {
        if (i >= j) {
            return 0; // 0 cuts
        }

        if (isPalindrome(s, i, j)) {
            return 0;  // 0 cuts as it's a palindrome
        }

        int cuts = INT_MAX;
        for (int k = i; k <= j-1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);

            cuts = min(temp, cuts);
        }
        return cuts;
    }

    int minCut(string s) {
        int n = s.length();

        return solve(s, 0, n-1);
    }
};


// Approach 2: Recursion + Memoization
// T.C : O(n^3)
// S.C : O(n^2)

class Solution {
public:
    int t[2001][2001];

    bool isPalindrome(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j) {
        if (i >= j) {
            return 0; // 0 cuts
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (isPalindrome(s, i, j)) {
            return t[i][j] = 0;  // 0 cuts as it's a palindrome
        }

        int cuts = INT_MAX;
        for (int k = i; k <= j-1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);

            cuts = min(temp, cuts);
        }
        return t[i][j] = cuts;
    }

    int minCut(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));

        return solve(s, 0, n-1);
    }
};

// Approach 3:  Bottom Up
// T.C : O(n^2)
// S.C : O(n^2)

class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // Blue print code use
        vector<vector<bool>> t(n, vector<bool>(n, false));
        // t[i][j] = true/false (s[i..j] substring is a palindrome or not)

        // Length = 1 substring
        for (int i=0; i < n; i++) {
            t[i][i] = true;  // s[i..i] is always a palindrome
        } 

        //Length >= 2
        for (int L = 2; L <= n; L++) {
            for (int i=0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (L == 2) { // string of size 2
                    t[i][j] = s[i] == s[j];
                } else {
                    t[i][j] = (s[i] == s[j]) && t[i+1][j-1];
                }
            }
        }

        vector<int> dp(n);
        // dp[i] = min cuts required to cut a string s[0...i] into palindrome

        for (int i=0; i < n; i++) {
            if (t[0][i] == true) { // s[0...i] is a palindrome
                dp[i] = 0; // no cuts required
            } else {
                dp[i] = INT_MAX;
                for (int k = 0; k < i; k++) {
                    if (t[k+1][i] == true && 1 + dp[k] < dp[i]) {
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};



/************************************************************ JAVA ************************************************************/

// Approach 1: Pure Recursive
// T.C : O(n * (2^n))
// S.C : O(n)


class Solution1 {
    private boolean isPalindrome(String s, int i, int j) {
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    private int solve(String s, int i, int j) {
        if (i >= j) {
            return 0; 
        }
        if (isPalindrome(s, i, j)) {
            return 0; 
        }

        int cuts = Integer.MAX_VALUE;
        for (int k = i; k <= j - 1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
            cuts = Math.min(temp, cuts);
        }
        return cuts;
    }

    public int minCut(String s) {
        int n = s.length();
        return solve(s, 0, n - 1);
    }
}

// Approach 2: Recursion + Memoization
// T.C : O(n^3)
// S.C : O(n^2)


class Solution2 {
    private int[][] t = new int[2001][2001];

    private boolean isPalindrome(String s, int i, int j) {
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    private int solve(String s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (isPalindrome(s, i, j)) {
            return t[i][j] = 0;
        }

        int cuts = Integer.MAX_VALUE;
        for (int k = i; k <= j - 1; k++) {
            int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
            cuts = Math.min(temp, cuts);
        }
        return t[i][j] = cuts;
    }

    public int minCut(String s) {
        int n = s.length();
        for (int i = 0; i < 2001; i++) {
            Arrays.fill(t[i], -1);
        }
        return solve(s, 0, n - 1);
    }
}


// Approach 3:  Bottom Up
// T.C : O(n^2)
// S.C : O(n^2)

class Solution {
    public int minCut(String s) {
        int n = s.length();

        boolean[][] t = new boolean[n][n];

        // Length = 1 substring are always palindrome
        for (int i=0; i < n; i++) {
            t[i][i] = true;
        }

        // Length >= 2 substrings
        for (int L = 2; L <= n; L++) {
            for (int i=0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (L == 2) {
                    t[i][j] = s.charAt(i) == s.charAt(j);
                } else {
                    t[i][j] = (s.charAt(i) == s.charAt(j)) && t[i+1][j-1];
                }
            }
        }

        // dp[i] = min cuts required to cut substring s[0..i] into palindromes
        int[] dp = new int[n];

        for (int i=0; i < n; i++) {
            if (t[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = Integer.MAX_VALUE;

                for (int k=0; k < i; k++) {
                    if (t[k+1][i] && 1 + dp[k] < dp[i]) {
                        dp[i] = dp[k] + 1;
                    }
                }
            }
        }
        return dp[n-1];
    }
}