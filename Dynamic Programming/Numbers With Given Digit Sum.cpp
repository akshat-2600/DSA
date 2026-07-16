/*
    Company Tags                : AMAZON
    Leetcode Link               : https://www.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum0733/1
*/


/******************************************************************** C++ ********************************************************************/

// Approach 1 : Pure Recursion
// T.C : O(10^N)
// S.C : O(N) (Stack space)

class Solution {
  public:
    int N;
  
    int solve(int pos, int remSum) {
        if (remSum < 0) {
            return 0;
        }
        
        if (pos == N) {
            return (remSum == 0);
        }
        
        int ways = 0;
        
        int start = (pos == 0) ? 1 : 0;
        
        for (int digit = start; digit <= 9; digit++) {
            
            ways += solve(pos+1, remSum - digit);
        
        }
        
        return ways;
    }
  
    int countWays(int n, int sum) {
        N = n;
        
        int ans = solve(0, sum); // pos, remaining sum
    
        return ans == 0 ? -1 : ans;
    }
};

// Approach 2 : Memoization (Top-Down)
// T.C : O(N * SUM * 10)
// S.C : O(N * SUM)

class Solution {
  public:
    int N;
    int t[10][82];
  
    int solve(int pos, int remSum) {
        if (remSum < 0) {
            return 0;
        }
        
        if (pos == N) {
            return (remSum == 0);
        }
        
        if (t[pos][remSum] != -1) {
            return t[pos][remSum];
        }
        
        int ways = 0;
        
        int start = (pos == 0) ? 1 : 0;
        
        for (int digit = start; digit <= 9; digit++) {
            
            ways += solve(pos+1, remSum - digit);
        
        }
        
        return t[pos][remSum] = ways;
    }
  
    int countWays(int n, int sum) {
        N = n;
        
        memset(t, -1, sizeof(t));
        
        int ans = solve(0, sum); // pos, remaining sum
    
        return ans == 0 ? -1 : ans;
    }
};


// Approach 3 : Bottom Up Dp
// T.C : O(N * SUM * 10)
// S.C : O(N * SUM)


class Solution {
  public:
    int countWays(int N, int sum) {
        
        if (sum <= 0 || sum > 9 * N) {
            return -1;
        }

        vector<vector<int>> dp(N+1, vector<int>(sum+1, 0));

        // Base case
        dp[N][0] = 1;

        // Fill table
        for (int pos = N - 1; pos >= 0; pos--) {

            for (int remSum = 0; remSum <= sum; remSum++) {

                int start = (pos == 0) ? 1 : 0;

                for (int digit = start; digit <= 9; digit++) {

                    if (remSum >= digit) {
                        dp[pos][remSum] += dp[pos + 1][remSum - digit];
                    }
                }
            }
        }

        return dp[0][sum] == 0 ? -1 : dp[0][sum];
    }
};

/******************************************************************** JAVA ********************************************************************/

// Approach 1 : Pure Recursion
// T.C : O(10^N)
// S.C : O(N) (Stack space)

class Solution {

    int N;

    int solve(int pos, int remSum) {

        if (remSum < 0) {
            return 0;
        }

        if (pos == N) {
            return remSum == 0 ? 1 : 0;
        }

        int ways = 0;

        int start = (pos == 0) ? 1 : 0;

        for (int digit = start; digit <= 9; digit++) {
            ways += solve(pos + 1, remSum - digit);
        }

        return ways;
    }

    public int countWays(int n, int sum) {

        N = n;

        if (sum <= 0 || sum > 9 * n) {
            return -1;
        }

        int ans = solve(0, sum);

        return ans == 0 ? -1 : ans;
    }
}

// Approach 2 : Memoization (Top-Down)
// T.C : O(N * SUM * 10)
// S.C : O(N * SUM)

class Solution {

    int N;
    int[][] dp = new int[10][82];

    int solve(int pos, int remSum) {

        if (remSum < 0) {
            return 0;
        }

        if (pos == N) {
            return remSum == 0 ? 1 : 0;
        }

        if (dp[pos][remSum] != -1) {
            return dp[pos][remSum];
        }

        int ways = 0;

        int start = (pos == 0) ? 1 : 0;

        for (int digit = start; digit <= 9; digit++) {
            ways += solve(pos + 1, remSum - digit);
        }

        return dp[pos][remSum] = ways;
    }

    public int countWays(int n, int sum) {

        if (sum <= 0 || sum > 9 * n) {
            return -1;
        }

        N = n;

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        int ans = solve(0, sum);

        return ans == 0 ? -1 : ans;
    }
}

// Approach 3 : Bottom Up Dp
// T.C : O(N * SUM * 10)
// S.C : O(N * SUM)

class Solution {
    public int countWays(int n, int sum) {
        
        if (sum <= 0 || sum > 9 * n) {
            return -1;
        }
        
        int[][] dp = new int[n + 1][sum + 1];
        
        dp[n][0] = 1;
        
        for (int pos = n-1; pos >= 0; pos--) {
            
            for (int remSum = 0; remSum <= sum; remSum++) {
                
                int start = (pos == 0) ? 1 : 0;
                
                for (int digit = start; digit <= 9; digit++) {
                    
                    if (remSum >= digit) {
                        dp[pos][remSum] += dp[pos+1][remSum-digit];
                    }
                }
            }
        }
        
        return dp[0][sum] == 0 ? -1 : dp[0][sum];
        
    }
};