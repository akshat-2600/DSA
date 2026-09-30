/*
    Company Tags        :    
    GeeksForGeeks Link  :   https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

*/


/******************************************************** C++ ********************************************************/

// Approach 1       : Pure Recursion
// Time Complexity  : O(2^(x+y))
// Space Complexity : O(x+y) 

class Solution {
  public:
    int MOD = 1e9 + 7;
  
    int ways(int x, int y) {
        
        if (x == 0 && y == 0) return 1;
        
        if (x < 0 || y < 0 || x > 500 || y > 500) {
            return 0;
        }
        
        return (ways(x-1, y) + ways(x, y-1)) % MOD;
        
    }
};


// Approach 2       : Recursion + Memoization
// Time Complexity  : O(x * y)
// Space Complexity : O(x * y)

class Solution {
  public:
    int MOD = 1e9 + 7;
    int t[501][501];
  
    int solve(int x, int y) {
        if (x == 0 && y == 0) return 1;
        
        if (x < 0 || y < 0 || x > 500 || y > 500) {
            return 0;
        }
        
        if (t[x][y] != -1) return t[x][y];
        
        return t[x][y] = (solve(x-1, y) + solve(x, y-1)) % MOD;
    }
  
    int ways(int x, int y) {
        memset(t, -1, sizeof(t));
        return solve(x, y) % MOD;
        
    }
};


// Approach 3       : Bottom Up DP
// Time Complexity  : O(x * y)
// Space Complexity : O(x * y)

class Solution {
  public:
    int MOD = 1e9 + 7;
  
    int ways(int x, int y) {
        
        if (x == 0 && y == 0) {
            return 1;
        }
        
        vector<vector<int>> t(501, vector<int>(501, 0));
        
        t[0][0] = 1;
        
        for (int j = 500; j > 0; j--) {
            t[0][j] = 1;
        }
        
        for (int i = 500; i > 0; i--) {
            t[i][0] = 1;
        }
        
        
        
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                t[i][j] = (t[i-1][j] + t[i][j-1]) % MOD;
            }
        }
        return t[x][y];
    }
};