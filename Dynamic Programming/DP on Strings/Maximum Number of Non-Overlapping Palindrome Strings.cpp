/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Recursion + Memoization
// T.C        : O(n^2 * n)
// S.C        : O(n^2)

class Solution {
public:
    int n;
    int t[2001][2001];

    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string& s, int k, int i, int j) {
        if (i >= n || j >= n) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (isPalindrome(s, i, j)) {
            int take  = 1 + solve(s, k, j+1, j+k);
            int grow  = solve(s, k, i, j+1);
            int slide = solve(s, k, i+1, j+1);

            return t[i][j] = max({take, grow, slide});

        } else {
            int grow  = solve(s, k, i, j+1);
            int slide = solve(s, k, i+1, j+1);

            return t[i][j] = max(grow, slide);
        }
    }

    int maxPalindromes(string s, int k) {
        n = s.length();
        if (k == 1) {
            return n;
        }

        memset(t, -1, sizeof(t));

        return solve(s, k, 0, k-1);
    }
};


// Approach-2 : Bottom up dp
// T.C        : O(n^2 * n)
// S.C        : O(n^2)

class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();

        if (k == 1) {
            return n;
        }

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                
                if (isPalindrome(s, i, j)) {
                    int take  = 1 + (j+k <= n ? t[j+1][j+k] : 0);
                    int grow  = t[i][j+1];
                    int slide = t[i+1][j+1];

                    t[i][j] = max({take, grow, slide});
                } else {
                    int grow  = t[i][j+1];
                    int slide = t[i+1][j+1];

                    t[i][j] = max(grow, slide);
                }
            }
        }
        return t[0][k-1];
    }
};


// Approach-3 : Recursion + Memoization + isPalindrome Constant time
// T.C        : O(n^2)
// S.C        : O(n^2)

class Solution {
public:
    int n;
    int t[2001][2001];

    int solve(string& s, int k, int i, int j, vector<vector<bool>>& isPalindrome) {
        if (i >= n || j >= n) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (isPalindrome[i][j]) {
            int take  = 1 + solve(s, k, j+1, j+k, isPalindrome);
            int grow  = solve(s, k, i, j+1, isPalindrome);
            int slide = solve(s, k, i+1, j+1, isPalindrome);

            return t[i][j] = max({take, grow, slide});

        } else {
            int grow  = solve(s, k, i, j+1, isPalindrome);
            int slide = solve(s, k, i+1, j+1, isPalindrome);

            return t[i][j] = max(grow, slide);
        }
    }

    int maxPalindromes(string s, int k) {
        n = s.length();
        if (k == 1) {
            return n;
        }
        memset(t, -1, sizeof(t));

        // isPalindrome in constant time
        vector<vector<bool>> isPalindrome(n+1, vector<bool>(n+1, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if (i == j) { // length = 1
                    isPalindrome[i][j] = true;
                } else if (i+1 == j) { // length = 2
                    isPalindrome[i][j] = s[i] == s[j];
                } else { // length greater than 2
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1]; 
                }
            }
        }

        return solve(s, k, 0, k-1, isPalindrome);
    }
};


// Approach-4 : Bottom Up DP + isPalindrome Constant time
// T.C        : O(n^2)
// S.C        : O(n^2)

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        if (k == 1) {
            return n;
        }

        // isPalindrome in constant time
        vector<vector<bool>> isPalindrome(n+1, vector<bool>(n+1, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if (i == j) { // length = 1
                    isPalindrome[i][j] = true;
                } else if (i+1 == j) { // length = 2
                    isPalindrome[i][j] = s[i] == s[j];
                } else { // length greater than 2
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1]; 
                }
            }
        }

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                
                if (isPalindrome[i][j]) {
                    int take  = 1 + (j+k <= n ? t[j+1][j+k] : 0);
                    int grow  = t[i][j+1];
                    int slide = t[i+1][j+1];

                    t[i][j] = max({take, grow, slide});
                } else {
                    int grow  = t[i][j+1];
                    int slide = t[i+1][j+1];

                    t[i][j] = max(grow, slide);
                }
            }
        }
        return t[0][k-1];
    }
};


// Approach-5 : Space optimized for Recursion + Memoization + isPalindrome Constant time
// T.C        : O(n^2)
// S.C        : O(n^2)

class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;

    int solve(string& s, int len, int k) {
        if (len < k) {
            return 0;
        }

        if (t[len] != -1) {
            return t[len];
        }

        int result = solve(s, len-1, k);

        int j = len - 1;
        for (int i = 0; j-i+1 >= k; i++) {
            if (isPalindrome[i][j]) {
                result = max(result, 1 + solve(s, i, k));
            }
        }
        return t[len] = result;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();

        isPalindrome.assign(n+1, vector<bool>(n+1, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (i+1 == j) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
                }
            }
        }

        t.assign(n+1, -1);

        return solve(s, n, k);
    }
};


// Approach-6 : Space optimized for Bottom Up Dp + isPalindrome Constant time
// T.C        : O(n^2)
// S.C        : O(n^2)

class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;

    int maxPalindromes(string s, int k) {
        int n = s.length();

        isPalindrome.assign(n+1, vector<bool>(n+1, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (i+1 == j) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
                }
            }
        }

        t.assign(n+1, -1);

        // Base case
        for (int len = 0; len < k; len++) {
            t[len] = 0;
        }

        for (int len = k; len <= n; len++) {
            int result = t[len-1];

            int j = len-1;
            for (int i = 0; j-i+1 >= k; i++) {
                if (isPalindrome[i][j]) {
                    result = max(result, 1 + t[i]);
                }
            }
            t[len] = result;
        }
        return t[n];
    }
};