/*  
    Company Tags         : 
    GeeksForGeeks Link   :  https://www.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences1729/1
*/

/****************************************************************** C++ ****************************************************/

// Approach : Only Recursion
// T.C      : O(2^N)
// S.C      : O(N)

class Solution {
  public:
    int solve(vector<int>& arr, int i, int prev) {
        // Base case - completion of all elements
        if (i == arr.size()) {
            return 0;
        }
        
        // Keep the current element unchanged
        int keep = abs(arr[i] - prev) + solve(arr, i+1, arr[i]);
        
        // Change the current element to 1
        int change = abs(1 - prev) + solve(arr, i+1, 1);
        
        return max(keep, change);
    }
  
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) {
            return 0;
        }
        
        // Try keeping the first element
        int keep   = solve(arr, 1, arr[0]);
        
        // Try keeping the first element to 1
        int change = solve(arr, 1, 1);
        
        return max(change, keep);
        
    }
};


// Approach : Recursion + Memoization
// T.C      : O(N^2)
// S.C      : O(N)

class Solution {
  public:
    int solve(vector<int>& arr, int i, int prev, unordered_map<string, int>& mp) {
        // Base case - completion of all elements
        if (i == arr.size()) {
            return 0;
        }
        
        string key = to_string(i) + "->" + to_string(prev);
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        
        // Keep the current element unchanged
        int keep = abs(arr[i] - prev) + solve(arr, i+1, arr[i], mp);
        
        // Change the current element to 1
        int change = abs(1 - prev) + solve(arr, i+1, 1, mp);
        
        return mp[key] = max(keep, change);
    }
  
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) {
            return 0;
        }
        
        unordered_map<string, int> mp;
        
        // Try keeping the first element
        int keep   = solve(arr, 1, arr[0], mp);
        
        // Try keeping the first element to 1
        int change = solve(arr, 1, 1, mp);
        
        return max(change, keep);
        
    }
};


// Approach : Bottom up DP
// T.C      : O(N)
// S.C      : O(N)

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // dp[i][0] -> Max sum up to index i if arr[i] remains unchanged 
        // dp[i][1] -> Max sum up to index i if arr[i] is changed to 1
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base case for index 0
        dp[0][0] = 0;  // Keeping arr[0] as arr[0]
        dp[0][1] = 0; // Keeping arr[0] to 1
        
        // Build the table iteratively from left to right
        for (int i = 1; i < n; i++) {
            // Case 1 : We decide to KEEP arr[i] unchanged
            int keep_from_keep   = dp[i-1][0] + abs(arr[i] - arr[i-1]);
            int keep_from_change = dp[i-1][1] + abs(arr[i] - 1);
            dp[i][0] = max(keep_from_keep, keep_from_change);
            
            // Case 2 : We decide to CHANGE arr[i] to 1
            int change_from_keep   = dp[i-1][0] + abs(1 - arr[i-1]);
            int change_from_change = dp[i-1][1] + abs(1 - 1);
            dp[i][1] = max(change_from_keep, change_from_change);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
