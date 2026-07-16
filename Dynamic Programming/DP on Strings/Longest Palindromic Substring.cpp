/*
    Company Tags                : AMAZON
    Leetcode Link               : https://www.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum0733/1
*/


/******************************************************************** C++ ********************************************************************/

// T.C : O(N^3)
// S.C : O(N)

class Solution {
public:
    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 1;
        }

        if (s[i] == s[j]) {
            return solve(s, i+1, j-1);
        }
        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {
                
                if (solve(s, i, j)) {
                    if (j-i+1 > maxlen) {
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};


// T.C : O(N^2)
// S.C : O(N^2) + O(N)

class Solution {
public:
    int t[1001][1001];

    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i+1, j-1);
        }
        return t[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        memset(t, -1, sizeof(t));

        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {
                
                if (solve(s, i, j)) {
                    if (j-i+1 > maxlen) {
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// T.C : O(N^3)
// S.C : O(1)

class Solution {
public:
    bool solve(string& s, int i, int j) {

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {

                if (solve(s, i, j)) {
                    if (j-i+1 > maxlen) {
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(startingIndex, maxlen);
    }
};


// T.C : O(N^2)
// S.C : O(N^2)


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = 0;
        int idx  = 0;

        vector<vector<bool>> t(n, vector<bool>(n));
        // t[i][j] = lps in s[i...j]

        for (int i=0; i < n; i++) {
            t[i][i] = true;
            maxLen    = 1;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i+L-1 < n; i++) {

                int j = i + L - 1;

                if (s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxLen = 2;
                    idx = i;

                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        idx = i;
                    } 
                } else {
                    t[i][j] = false;
                }
            }
        }

        return s.substr(idx, maxLen);
    }
};



/******************************************************************** JAVA ********************************************************************/

// T.C : O(N^3)
// S.C : O(N)

class Solution {
    private boolean solve(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (s.charAt(i) == s.charAt(j)) {
            return solve(s, i+1, j-1);
        }

        return false;
    }

    public String longestPalindrome(String s) {
        
        int n = s.length();

        int maxLen = 0;
        int start  = 0;

        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {

                if (solve(s, i, j)) {
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substring(start, start + maxLen);
    }
}


// T.C : O(N^2)
// S.C : O(N^2) + O(N)

class Solution {
    int[][] dp;

    private boolean solve(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        if (s.charAt(i) == s.charAt(j)) {
            dp[i][j] = solve(s, i+1, j-1) ? 1 : 0;
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j] == 1;
    }

    public String longestPalindrome(String s) {
        
        int n = s.length();

        dp = new int[n][n];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        int maxLen = 0;
        int start  = 0;

        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {

                if (solve(s, i, j)) {
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substring(start, start + maxLen);
    }
}

// T.C : O(N^3)
// S.C : O(1)


class Solution {

    private boolean solve(String s, int i, int j) {

        while (i <= j) {

            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    public String longestPalindrome(String s) {

        int n = s.length();

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (solve(s, i, j)) {

                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substring(start, start + maxLen);
    }
}


// T.C : O(N^2)
// S.C : O(N^2)

class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();

        boolean[][] dp = new boolean[n][n];

        int maxLen = 1;
        int start = 0;

        for (int i=0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i=0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (s.charAt(i) == s.charAt(j)) {
                    if (L == 2 || dp[i+1][j-1]) {
                        dp[i][j] = true;

                        if (L > maxLen) {
                            maxLen = L;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substring(start, start + maxLen);
    }
}

