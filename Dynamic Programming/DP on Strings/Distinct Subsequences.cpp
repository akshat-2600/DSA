/*
    Company Tags    :   GOOGLE
    Leetcode Link   :   https://leetcode.com/problems/distinct-subsequences-ii/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Pure Recursion
// T.C        : O(2^n)
// S.C        : O(3^n)   

class Solution {
  public:
    int n;
    
    int solve(int idx, int incIdx, int decIdx, vector<int>& arr) {
        if (idx == n) {
            return 0;
        }
        
        int take1 = INT_MAX;
        int take2 = INT_MAX;
        int skip  = INT_MAX;
        
        skip = 1 + solve(idx+1, incIdx, decIdx, arr);
        
        if (incIdx == -1 || arr[idx] > arr[incIdx]) {
            take1 = solve(idx+1, idx, decIdx, arr);
        }
        if (decIdx == -1 || arr[idx] < arr[decIdx]) {
            take2 = solve(idx+1, incIdx, idx, arr);
        }
        
        return min({take1, take2, skip});
    }
  
    int minCount(vector<int>& arr) {
        
        n = arr.size();
        
        return solve(0, -1, -1, arr);
        
    }
};


// Approach-2 : Recursion + Memoization
// T.C        : O(n^3)
// S.C        : o(n^3)  

class Solution {
  public:
    int n;
    int dp[101][101][101];
    
    int solve(int idx, int incIdx, int decIdx, vector<int>& arr) {
        if (idx == n) {
            return 0;
        }
        
        if (dp[idx][incIdx+1][decIdx+1] != -1) {
            return dp[idx][incIdx+1][decIdx+1];
        }
        
        int take1 = INT_MAX;
        int take2 = INT_MAX;
        int skip  = INT_MAX;
        
        skip = 1 + solve(idx+1, incIdx, decIdx, arr);
        
        if (incIdx == -1 || arr[idx] > arr[incIdx]) {
            take1 = solve(idx+1, idx, decIdx, arr);
        }
        if (decIdx == -1 || arr[idx] < arr[decIdx]) {
            take2 = solve(idx+1, incIdx, idx, arr);
        }
        
        
        return dp[idx][incIdx+1][decIdx+1] = min({take1, take2, skip});
    }
  
    int minCount(vector<int>& arr) {
        
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, -1, -1, arr);
        
    }
};

// Approach-3 : Bottom Up
// T.C        : O(n^3)
// S.C        : O(n^3)

class Solution {
  public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
        
        for (int i = 0; i <= n; i++) {
            for (int d = 0; d <= n; d++) {
                dp[n][i][d] = 0;
            }
        }
        
        for (int idx = n-1; idx >= 0; idx--) {
            for (int inc = 0; inc <= n; inc++) {
                for (int dec = 0; dec <= n; dec++) {
                    int take1 = INT_MAX;
                    int take2 = INT_MAX;
                    int skip  = INT_MAX;
                    
                    skip = 1 + dp[idx + 1][inc][dec];
                    
                    if (inc == 0 || arr[idx] > arr[inc - 1]) {
                        take1 = dp[idx+1][idx+1][dec];
                    }
                    
                    
                    if (dec == 0 || arr[idx] < arr[dec - 1]) {
                        take2 = dp[idx+1][inc][idx+1];
                    } 
                    
                    dp[idx][inc][dec] = min({take1, take2, skip});
                }
            }
        }
        return dp[0][0][0];
    }
};

// Approach-4 : Bottom Up Space Optimized
// T.C        : O(n^3)
// S.C        : O(n^2)

class Solution {
  public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> next(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> curr(n + 1, vector<int>(n + 1, 0));
        
        for (int idx = n-1; idx >= 0; idx--) {
            for (int inc = 0; inc <= n; inc++) {
                for (int dec = 0; dec <= n; dec++) {
                    int take1 = INT_MAX;
                    int take2 = INT_MAX;
                    int skip  = INT_MAX;
                    
                    skip = 1 + next[inc][dec];
                    
                    if (inc == 0 || arr[idx] > arr[inc - 1]) {
                        take1 = next[idx+1][dec];
                    }
                    
                    
                    if (dec == 0 || arr[idx] < arr[dec - 1]) {
                        take2 = next[inc][idx+1];
                    } 
                    
                    curr[inc][dec] = min({take1, take2, skip});
                }
            }
            next = curr;
        }
        return next[0][0];
    }
};


/******************************************************** JAVA ********************************************************/

//coming soon