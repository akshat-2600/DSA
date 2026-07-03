/*
    Company Tags                : 
    GeekForGeeks Link           : https://www.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1?_gl=1*t84o1j*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg
*/

/************************************************************ C++ ************************************************************************/

// T.C : O(n * 2^n)
// S.C : O(1)
// Stack Space : O(n)

// Recursion

class Solution {
  public:
    int solve(vector<int>& arr, int i, bool skipped) {
        
        // Base case
        if (i == arr.size()) {
            return INT_MIN;
        }
        
        // Start a new subarray from arr[i]
        int take = arr[i];
        
        // Extend the current subarray
        int next = solve(arr, i+1, skipped);
        
        if (next != INT_MIN) {
            take = max(take, arr[i] + max(0, next));
        }
        
        // Skip current element (only once)
        int skip = INT_MIN;
        if (!skipped) {
            skip = solve(arr, i+1, true);
        }
        
        return max(take, skip);
    }
  
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int ans = INT_MIN;
        for (int i=0; i<n; i++) {
            ans = max(ans, solve(arr, i, false));
        }
        
        return ans;
        
    }
};


// T.C : O(n^2)
// S.C : O(n)

// Recursion + Memoization

class Solution {
  public:
    int solve(vector<int>& arr, int i, bool skipped, vector<vector<int>>& t) {
        
        // Base case
        if (i == arr.size()) {
            return INT_MIN;
        }
        
        if (t[i][skipped] != INT_MIN) {
            return t[i][skipped];
        }
        
        // Start a new subarray from arr[i]
        int take = arr[i];
        
        // Extend the current subarray
        int next = solve(arr, i+1, skipped, t);
        
        if (next != INT_MIN) {
            take = max(take, arr[i] + max(0, next));
        }
        
        // Skip current element (only once)
        int skip = INT_MIN;
        if (!skipped) {
            skip = solve(arr, i+1, true, t);
        }
        
        return t[i][skipped] = max(take, skip);
    }
  
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> t(n, vector<int>(2, INT_MIN));
        
        int ans = INT_MIN;
        for (int i=0; i<n; i++) {
            ans = max(ans, solve(arr, i, false, t));
        }
        
        return ans;
        
    }
};


/************************************************************ JAVA ************************************************************************/

import java.util.Arrays;

class Solution {
    
    // ==========================================
    // APPROACH 1: PURE RECURSION
    // Time Complexity: O(n * 2^n) | Space: O(n)
    // ==========================================
    public int solve(int[] arr, int i, boolean skipped) {
        // Base case: out of bounds
        if (i == arr.length) {
            return Integer.MIN_VALUE;
        }
        
        // Option 1: Start a new subarray or extend current subarray
        int take = arr[i];
        int next = solve(arr, i + 1, skipped);
        
        if (next != Integer.MIN_VALUE) {
            take = Math.max(take, arr[i] + Math.max(0, next));
        }
        
        // Option 2: Skip current element (allowed only once)
        int skip = Integer.MIN_VALUE;
        if (!skipped) {
            skip = solve(arr, i + 1, true);
        }
        
        return Math.max(take, skip);
    }
    
    public int maxSumSubarray(int[] arr) {
        int n = arr.length;
        int ans = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, solve(arr, i, false));
        }
        
        return ans;
    }

    // ==========================================
    // APPROACH 2: RECURSION + MEMOIZATION (DP)
    // Time Complexity: O(n) | Space: O(n)
    // ==========================================
    public int solveMemoized(int[] arr, int i, boolean skipped, int[][] t) {
        // Base case: out of bounds
        if (i == arr.length) {
            return Integer.MIN_VALUE;
        }
        
        // Convert boolean to index: false -> 0, true -> 1
        int skipIndex = skipped ? 1 : 0;
        
        // Return if state is already computed
        if (t[i][skipIndex] != Integer.MIN_VALUE) {
            return t[i][skipIndex];
        }
        
        // Option 1: Start a new subarray or extend current subarray
        int take = arr[i];
        int next = solveMemoized(arr, i + 1, skipped, t);
        
        if (next != Integer.MIN_VALUE) {
            take = Math.max(take, arr[i] + Math.max(0, next));
        }
        
        // Option 2: Skip current element (allowed only once)
        int skip = Integer.MIN_VALUE;
        if (!skipped) {
            skip = solveMemoized(arr, i + 1, true, t);
        }
        
        // Store and return the result
        return t[i][skipIndex] = Math.max(take, skip);
    }
    
    public int maxSumSubarrayMemoized(int[] arr) {
        int n = arr.length;
        
        // Create an n x 2 memoization grid
        int[][] t = new int[n][2];
        for (int[] row : t) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, solveMemoized(arr, i, false, t));
        }
        
        return ans;
    }
}

