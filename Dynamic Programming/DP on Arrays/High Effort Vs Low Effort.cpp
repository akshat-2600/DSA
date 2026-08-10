/*
    Company Tag           : 
    GeeksForGeeks Link    :  https://www.geeksforgeeks.org/problems/high-effort-vs-low-effort0213/1
    
*/

// Approach : Recursion 
// T.C      : O(3^n)
// S.C      : O(n)  (recursion stack)

class Solution {
  public:
    int solve(int i, int can_take_high, vector<int>& h, vector<int>& l) {
        if (i >= h.size()) {
            return 0;
        }
        
        // Choice 1: Rest today (allows high-effort tomorrow)
        int rest = solve(i+1, 1, h, l);
        
        // Choice 2: Low-effort today (does not allow high-effort tomorrow)
        int low = l[i] + solve(i+1, 0, h, l);
        
        // Choice 3: High-effort today (only valid if previous day was a rest day)
        int high = 0;
        if (can_take_high) {
            high = h[i] + solve(i+1, 0, h, l);
        }
        
        return max({rest, low, high});
    }
  
    int maxTask(vector<int>& h, vector<int>& l) {
        
        return solve(0, 1, h, l);
    }
};

// Approach : Memoization 
// T.C      : O(2*n)
// S.C      : O(2*n)  (recursion stack)

class Solution {
  public:
    int t[100005][2];
  
    int solve(int i, int can_take_high, vector<int>& h, vector<int>& l) {
        if (i >= h.size()) {
            return 0;
        }
        
        if (t[i][can_take_high] != -1) {
            return t[i][can_take_high];
        }
        
        // Choice 1: Rest today (allows high-effort tomorrow)
        int rest = solve(i+1, 1, h, l);
        
        // Choice 2: Low-effort today (does not allow high-effort tomorrow)
        int low = l[i] + solve(i+1, 0, h, l);
        
        // Choice 3: High-effort today (only valid if previous day was a rest day)
        int high = 0;
        if (can_take_high) {
            high = h[i] + solve(i+1, 0, h, l);
        }
        
        return t[i][can_take_high] = max({rest, low, high});
    }
  
    int maxTask(vector<int>& h, vector<int>& l) {
        
        memset(t, -1, sizeof(t));
        
        return solve(0, 1, h, l);
    }
};

// Approach : Bottom up dp
// T.C      : O(n)
// S.C      : O(n)

class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        
        int n = h.size();
        
        // dp[i][0] = max tasks from day i onward if previous day was NOT a rest day
        // dp[i][1] = max tasks from day i onward if previous day WAS a rest day
        // Size n + 1 handles the base case (i == n) automatically as 0
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        // Iterate backwards from the last day down to day 0
        for (int i = n - 1; i >= 0; i--) {
            for (int can_take_high = 0; can_take_high <= 1; can_take_high++) {
                
                // Choice 1: Rest today (allows high-effort tomorrow)
                int rest = dp[i + 1][1];

                // Choice 2: Low-effort today (does not allow high-effort tomorrow)
                int low = l[i] + dp[i + 1][0];

                // Choice 3: High-effort today (only valid if previous day was a rest day)
                int high = 0;
                if (can_take_high) {
                    high = h[i] + dp[i + 1][0];
                }

                // Save the optimal decision for the current state
                dp[i][can_take_high] = ({rest, low, high});
            }
        }

        // Equivalent to the initial recursive call: solve(0, 1)
        return dp[0][1];
    }
};