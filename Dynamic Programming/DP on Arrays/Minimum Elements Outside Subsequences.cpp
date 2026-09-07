/*
    Company Tags    :   SWIGGY
    Leetcode Link   :   https://leetcode.com/problems/distinct-subsequences/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Pure Recursion
// T.C        : O(2^n)
// S.C        : O(2^n)   

class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    unordered_set<string> st;

    int solve(int i, string& s, string temp) {
        // Base case
        if (i == n) {
            cout << temp << endl;
            if (temp == "") {
                return 0;
            }
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                return 1;
            } else {
                return 0;
            }   
        }

        int skip = solve(i+1, s, temp);
        temp.push_back(s[i]);
        int take = solve(i+1, s, temp);

        return ((take % MOD) + (skip % MOD)) % MOD;
    }

    int distinctSubseqII(string s) {
        n = s.length();
        string temp = "";

        return solve(0, s, temp);
    }
};


// Approach-2 : Recursion + Memoization with duplicate handling
// T.C        : O(n)
// S.C        : o(n)  

class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[2001];
    vector<int> prev;  // last time when we saw this nth character (1-based indexing)

    int solve(int n) {
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int total = (2 * solve(n-1)) % MOD;

        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + MOD) % MOD;
        }
        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n) - 1 + MOD) % MOD;
    }
};

// Approach-3 : Bottom Up with duplicate handling
// T.C        : O(n)
// S.C        : O(n)

class Solution {
public:
    int MOD = 1e9 + 7;

    int distinctSubseqII(string s) {
        int n = s.length();

        vector<int> dp(n+1, 0);
        vector<int> prev(n+1, 0);
        vector<int> lastSeen(26, 0);

        for (int i = 1; i <= n; i++) {
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }    

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int total = (2 * dp[i-1]) % MOD;

            if (prev[i] != 0) {
                int duplicates = dp[prev[i] - 1];
                total = (total - duplicates + MOD) % MOD; 
            }
            dp[i] = total;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};

/******************************************************** JAVA ********************************************************/

//coming soon