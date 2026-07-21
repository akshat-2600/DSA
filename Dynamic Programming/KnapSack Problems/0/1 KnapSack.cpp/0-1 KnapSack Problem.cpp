/*
    Company Tags            : FLIPKART, MORGAN STANLEY, AMAZON, MICROSOFT, SNAPDEAL, ORACLE, PAYU, VISA, DIRECTI, GREYORANGE, MOBICIP, NPCI
    GeeksForGeeks Link      : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1 


/************************************************************ C++ ************************************************************/

// Approach : Pure Recursion
// T.C      : O(2^n)
// S.C      : O(n) recursion

class Solution {
  public:
    int n;
  
    int solve(int i, int W, vector<int>& val, vector<int> &wt) {
        if (i >= n || W == 0) {
            return 0;
        }
        
        int take = 0;
        int skip = 0;
        
        if (wt[i] <= W) {
            take = val[i] + solve(i+1, W - wt[i], val, wt);
        }
        skip = solve(i+1, W, val, wt);
        
        return max(take, skip);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        n = val.size();
        
        return solve(0, W, val, wt);
        
    }
};

// Approach : Memoization (Forward)
// T.C      : O(n*W)
// S.C      : O(n*W)


class Solution {
  public:
    int n;
    int t[1001][1001];
  
    int solve(int i, int W, vector<int>& val, vector<int> &wt) {
        if (i >= n || W == 0) {
            return 0;
        }
        
        if (t[i][W] != -1) {
            return t[i][W];
        }
        
        int take = 0;
        int skip = 0;
        
        if (wt[i] <= W) {
            take = val[i] + solve(i+1, W - wt[i], val, wt);
        }
        skip = solve(i+1, W, val, wt);
        
        return t[i][W] = max(take, skip);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        n = val.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, W, val, wt);
        
    }
};

// Approach : Memoization (Backward)
// T.C      : O(n*W)
// S.C      : O(n*W)

class Solution {
  public:
    int n;
    int t[1001][1001];
  
    int solve(int i, int W, vector<int>& val, vector<int> &wt) {
        if (i < 0 || W == 0) {
            return 0;
        }
        
        if (t[i][W] != -1) {
            return t[i][W];
        }
        
        int take = 0;
        int skip = 0;
        
        if (wt[i] <= W) {
            take = val[i] + solve(i-1, W - wt[i], val, wt);
        }
        skip = solve(i-1, W, val, wt);
        
        return t[i][W] = max(take, skip);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        n = val.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(n-1, W, val, wt);
        
    }
};

// Approach : Bottom up 
// T.C      : O(n*W)
// S.C      : O(n*W)


class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
        //t[i][j]
        vector<vector<int>> t(n+1, vector<int>(W+1));
        
        // Base case : if (n == 0) return 0
        for (int j = 0; j < W+1; j++) {
            t[0][j] = 0;
        }
        
        // Base case : if (W == 0) return 0
        for (int i = 0; i < n+1; i++) {
            t[i][0] = 0;
        }
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                //take
                if (wt[i-1] <= j) {
                    take = val[i-1] + t[i-1][j - wt[i-1]];
                }
                
                skip = t[i-1][j];
                
                t[i][j] = max(take, skip);
            }
        }
        
        return t[n][W];
    }
};

// Approach : Space Optimized 
// T.C      : O(n*W)
// S.C      : O(W)

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
        // prev -> t[i-1][...]
        // curr -> t[i][...]
        vector<int> prev(W+1, 0);
        vector<int> curr(W+1, 0);
        
        for (int i = 1; i < n+1; i++) {
            
            for (int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                // take -> t[i-1][j - wt[i-1]]
                if (wt[i-1] <= j) {
                    take = val[i-1] + prev[j - wt[i-1]];
                }
                
                //skip -> t[i-1][j]
                skip = prev[j];
                
                //t[i][j]
                curr[j] = max(take, skip);
            }
            
            // move current row -> previous row
            prev = curr;
        }
        
        return prev[W]; // same ast[n][W];
    }
};


/************************************************************ Java ************************************************************/



// Approach : Pure Recursion
// T.C      : O(2^n)
// S.C      : O(n) recursion

class Solution {

    int n;

    int solve(int i, int W, int[] val, int[] wt) {
        if (i >= n || W == 0) {
            return 0;
        }

        int take = 0;
        int skip;

        if (wt[i] <= W) {
            take = val[i] + solve(i + 1, W - wt[i], val, wt);
        }

        skip = solve(i + 1, W, val, wt);

        return Math.max(take, skip);
    }

    public int knapsack(int W, int val[], int wt[]) {

        n = val.length;

        return solve(0, W, val, wt);
    }
}

// Approach : Memoization (Forward)
// T.C      : O(n*W)
// S.C      : O(n*W)

import java.util.Arrays;

class Solution {

    int n;
    int[][] dp;

    int solve(int i, int W, int[] val, int[] wt) {

        if (i >= n || W == 0) {
            return 0;
        }

        if (dp[i][W] != -1) {
            return dp[i][W];
        }

        int take = 0;
        int skip;

        if (wt[i] <= W) {
            take = val[i] + solve(i + 1, W - wt[i], val, wt);
        }

        skip = solve(i + 1, W, val, wt);

        return dp[i][W] = Math.max(take, skip);
    }

    public int knapsack(int W, int val[], int wt[]) {

        n = val.length;

        dp = new int[n][W + 1];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, W, val, wt);
    }
}


// Approach : Memoization (Backward)
// T.C      : O(n*W)
// S.C      : O(n*W)

import java.util.Arrays;

class Solution {

    int[][] dp;

    int solve(int i, int W, int[] val, int[] wt) {

        if (i < 0 || W == 0) {
            return 0;
        }

        if (dp[i][W] != -1) {
            return dp[i][W];
        }

        int take = 0;
        int skip;

        if (wt[i] <= W) {
            take = val[i] + solve(i - 1, W - wt[i], val, wt);
        }

        skip = solve(i - 1, W, val, wt);

        return dp[i][W] = Math.max(take, skip);
    }

    public int knapsack(int W, int val[], int wt[]) {

        int n = val.length;

        dp = new int[n][W + 1];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(n - 1, W, val, wt);
    }
}


// Approach : Bottom up 
// T.C      : O(n*W)
// S.C      : O(n*W)

class Solution {

    public int knapsack(int W, int val[], int wt[]) {

        int n = val.length;

        int[][] dp = new int[n + 1][W + 1];

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= W; j++) {

                int take = 0;
                int skip;

                if (wt[i - 1] <= j) {
                    take = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                }

                skip = dp[i - 1][j];

                dp[i][j] = Math.max(take, skip);
            }
        }

        return dp[n][W];
    }
}

// Approach : Space Optimized 
// T.C      : O(n*W)
// S.C      : O(W)


class Solution {

    public int knapsack(int W, int val[], int wt[]) {

        int n = val.length;

        int[] prev = new int[W + 1];
        int[] curr = new int[W + 1];

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= W; j++) {

                int take = 0;
                int skip;

                if (wt[i - 1] <= j) {
                    take = val[i - 1] + prev[j - wt[i - 1]];
                }

                skip = prev[j];

                curr[j] = Math.max(take, skip);
            }

            prev = curr.clone();
        }

        return prev[W];
    }
}