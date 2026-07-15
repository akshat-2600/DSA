/*
    Company Tags                :  Microsoft
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1



/**************************************************************** C++ ****************************************************************/

// Approach : Pure Recursion
// T.C      : O(n^2)
// S.C      : O(n)  (Recursion stack)

class Solution {
public:

    int solve(vector<int>& arr, int idx, bool decreasing) {

        if (idx == arr.size() - 1)
            return 1;

        // Increasing phase
        if (!decreasing) {

            if (arr[idx] <= arr[idx + 1]) {

                int stayInc = 1 + solve(arr, idx + 1, false);

                int switchDec = 1 + solve(arr, idx + 1, true);

                return max(stayInc, switchDec);
            }
        }

        // Decreasing phase
        if (arr[idx] >= arr[idx + 1]) {

            return 1 + solve(arr, idx + 1, true);
        }

        // Bitonic subarray ends
        return 1;
    }

    int bitonic(vector<int>& arr) {

        int ans = 1;

        for (int i = 0; i < arr.size(); i++) {

            ans = max(ans, solve(arr, i, false));
        }

        return ans;
    }
};


// Approach : Memoization (Top Down Dp)
// T.C      : O(n)
// S.C      : O(n)  (DP table + Recursion stack)

class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<int>& arr, int idx, bool decreasing) {

        if (idx == arr.size() - 1)
            return 1;

        int state = decreasing ? 1 : 0;

        if (dp[idx][state] != -1)
            return dp[idx][state];

        // Increasing phase
        if (!decreasing) {

            if (arr[idx] <= arr[idx + 1]) {

                int stayInc = 1 + solve(arr, idx + 1, false);

                int switchDec = 1 + solve(arr, idx + 1, true);

                return dp[idx][state] = max(stayInc, switchDec);
            }
        }

        // Decreasing phase
        if (arr[idx] >= arr[idx + 1]) {

            return dp[idx][state] = 1 + solve(arr, idx + 1, true);
        }

        return dp[idx][state] = 1;
    }

    int bitonic(vector<int>& arr) {

        int n = arr.size();

        dp.assign(n, vector<int>(2, -1));

        int ans = 1;

        for (int i = 0; i < n; i++) {

            ans = max(ans, solve(arr, i, false));
        }

        return ans;
    }
};


// Approach : Bottom Up Dp
// T.C      : O(n)
// S.C      : O(n) 


class Solution {
public:

    int bitonic(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2));

        // Base Case
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;

        for (int idx = n - 2; idx >= 0; idx--) {

            // Increasing phase
            if (arr[idx] <= arr[idx + 1]) {

                int stayInc = 1 + dp[idx + 1][0];

                int switchDec = 1 + dp[idx + 1][1];

                dp[idx][0] = max(stayInc, switchDec);
            }
            else {

                dp[idx][0] = 1 + dp[idx + 1][1];
            }

            // Decreasing phase
            if (arr[idx] >= arr[idx + 1]) {

                dp[idx][1] = 1 + dp[idx + 1][1];
            }
            else {

                dp[idx][1] = 1;
            }
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {

            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};

/*********************************************************** JAVA **************************************************/

// Approach : Pure Recursion
// T.C      : O(n^2)
// S.C      : O(n)  (Recursion stack)

class Solution {
    
    // Solve function returns the maximum length of a biotonic subarray starting from index idx
    private int solve(int[] arr, int idx, boolean decreasing) {
        if (idx == arr.length - 1) {
            return 1;
        }
        
        // Continue in increasing phase
        if (!decreasing) {
            
            if (arr[idx] <= arr[idx+1]) {
                // Stay increasing
                int stayInc = 1 + solve(arr, idx+1, false);
                
                // Switch to decreasing at next element
                int switchDec = 1 + solve(arr, idx+1, true);
                
                return Math.max(stayInc, switchDec);
            }
        }
        
        // Already in decreasing phase
        if (arr[idx] >= arr[idx+1]) {
            return 1 + solve(arr, idx+1, true);
        }
        
        // Biotonic subarray ends here
        return 1;
    }
    
    public int bitonic(int[] arr) {
        
        int ans = 1;
        
        // Try every index as the starting point
        for (int i = 0; i < arr.length; i++) {
            ans = Math.max(ans, solve(arr, i, false));
        }
        
        return ans;
    }
}

// Approach : Memoization (Top Down Dp)
// T.C      : O(n)
// S.C      : O(n)  (DP table + Recursion stack)

class Solution {
    
    int[][] dp;
    
    // Solve function returns the maximum length of a biotonic subarray starting from index idx
    private int solve(int[] arr, int idx, boolean decreasing) {
        
        // Base case
        if (idx == arr.length - 1) {
            return 1;
        }
        
        int state = decreasing ? 1 : 0;
        
        // Already computed
        if (dp[idx][state] != -1) {
            return dp[idx][state];
        }
        
        // Continue in increasing phase
        if (!decreasing) {
            
            if (arr[idx] <= arr[idx+1]) {
                // Stay increasing
                int stayInc = 1 + solve(arr, idx+1, false);
                
                // Switch to decreasing at next element
                int switchDec = 1 + solve(arr, idx+1, true);
                
                return dp[idx][state] = Math.max(stayInc, switchDec);
            }
        }
        
        // Already in decreasing phase
        if (arr[idx] >= arr[idx+1]) {
            return dp[idx][state] = 1 + solve(arr, idx+1, true);
        }
        
        // Biotonic subarray ends here
        return dp[idx][state] = 1;
    }
    
    public int bitonic(int[] arr) {
        
        int n = arr.length;
        
        dp = new int[n][2];
        
        for (int[] row: dp) {
            Arrays.fill(row, -1);
        }
        
        int ans = 1;
        
        // Try every index as the starting point
        for (int i = 0; i < arr.length; i++) {
            ans = Math.max(ans, solve(arr, i, false));
        }
        
        return ans;
    }
}


// Approach : Bottom Up Dp
// T.C      : O(n)
// S.C      : O(n) 


class Solution {
    public int bitonic(int[] arr) {
        
        int n = arr.length;
        
        int[][] dp = new int[n][2];
        
        // Base Case
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;
        
        for (int idx = n-2; idx >= 0; idx--) {
            
            // State 0 -> Increasing phase
            if (arr[idx] <= arr[idx+1]) {
                
                int stayInc = 1 + dp[idx+1][0];
                
                int switchDec = 1 + dp[idx+1][1];
                
                dp[idx][0] = Math.max(stayInc, switchDec);
                
            } else {
                // Must switch to decreasing phase
                dp[idx][0] = 1 + dp[idx+1][1];
            }
            
            // State 1-> Decreasing Phase
            if (arr[idx] >= arr[idx+1]) {
                
                dp[idx][1] = 1 + dp[idx+1][1];
            
                
            } else {
                dp[idx][1] = 1;
            }
        }
        int ans = 1;
        
        for (int i=0; i < n; i++) {
            ans = Math.max(ans, dp[i][0]);
        }
        return ans;
    }
}

