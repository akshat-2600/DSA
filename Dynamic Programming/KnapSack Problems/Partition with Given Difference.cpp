/*
    Company Tag                 : 
    Leetcode Link               : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
*/


/*************************************************************** C++ *************************************************/

// Approach 1: Pure Recursion
// T.C       : O(2^n)
// S.C       : O(n)  (recursion call stack)

class Solution {
  public:
    int n;
    
    int solve(vector<int>& arr, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        
        int skip = solve(arr, target, n-1);
        
        int take = 0;
        if (arr[n-1] <= target) {
            take = solve(arr, target - arr[n-1], n-1);
        }
        
        return take + skip;
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        
        n = arr.size();

        int S = accumulate(arr.begin(), arr.end(), 0);
        
        if ((S+diff) % 2 != 0) return 0;
        
        int target = (S + diff) / 2;
        
        return solve(arr, target, n);
    }
};

// Approach 2: Recursion + Memoization
// T.C       : O(n*target)
// S.C       : O(n*target)  


class Solution {
  public:
    int n;
    int t[1001][1001];
    
    int solve(vector<int>& arr, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        
        if (t[n][target] != -1) {
            return t[n][target];
        }
        
        int skip = solve(arr, target, n-1);
        
        int take = 0;
        if (arr[n-1] <= target) {
            take = solve(arr, target - arr[n-1], n-1);
        }
        
        return t[n][target] = take + skip;
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        
        n = arr.size();

        int S = accumulate(arr.begin(), arr.end(), 0);
        
        if ((S+diff) % 2 != 0) return 0;
        
        int target = (S + diff) / 2;

        memset(t, -1, sizeof(t));
        
        return solve(arr, target, n);
    }
};


// Approach 3: Bottom Up
// T.C       : O(n*target)
// S.C       : O(n*target)  


class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        
        int n = arr.size();

        int S = accumulate(arr.begin(), arr.end(), 0);
        
        if ((S+diff) % 2 != 0) return 0;
        
        int target = (S + diff) / 2;
        
        vector<vector<int>> t(n+1, vector<int>(target+1, 0));
        
        t[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int skip = t[i-1][j];
                
                int take = 0;
                if (arr[i-1] <= j) {
                    take = t[i-1][j - arr[i-1]];
                }
                
                t[i][j] = take + skip;
            }
        }
        return t[n][target];
    }
};

// Approach 4: Bottom Up Space Optimized
// T.C       : O(n*target)
// S.C       : O(target)  

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        
        int n = arr.size();

        int S = accumulate(arr.begin(), arr.end(), 0);
        
        if ((S+diff) % 2 != 0) return 0;
        
        int target = (S + diff) / 2;
        
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        
        prev[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int skip = prev[j];
                
                int take = 0;
                if (arr[i-1] <= j) {
                    take = prev[j - arr[i-1]];
                }
                
                curr[j] = take + skip;
            }
            prev = curr;
        }
        return prev[target];
    }
};



/*************************************************************** JAVA *************************************************/

// Approach 1: Pure Recursion
// T.C       : O(2^n)
// S.C       : O(n)  (recursion call stack)

import java.util.*;

class Solution {
    private int n;
    
    private int solve(int[] arr, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        
        int skip = solve(arr, target, n - 1);
        
        int take = 0;
        if (arr[n - 1] <= target) {
            take = solve(arr, target - arr[n - 1], n - 1);
        }
        
        return take + skip;
    }
  
    public int countPartitions(int[] arr, int diff) {
        n = arr.length;
        
        int s = 0;
        for (int num : arr) {
            s += num;
        }

        if ((s + diff) % 2 != 0) {
            return 0;
        }

        int target = (s + diff) / 2;

        return solve(arr, target, n);
    }
}



// Approach 2: Recursion + Memoization
// T.C       : O(n*target)
// S.C       : O(n*target)  

import java.util.*;

class Solution {
    private int n;
    private int[][] t = new int[1001][1001];
    
    private int solve(int[] arr, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        
        if (t[n][target] != -1) {
            return t[n][target];
        }
        
        int skip = solve(arr, target, n - 1);
        
        int take = 0;
        if (arr[n - 1] <= target) {
            take = solve(arr, target - arr[n - 1], n - 1);
        }
        
        return t[n][target] = take + skip;
    }
  
    public int countPartitions(int[] arr, int diff) {
        n = arr.length;
        
        // Initializing the memoization table with -1
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int s = 0;
        for (int num : arr) {
            s += num;
        }

        if ((s + diff) % 2 != 0) {
            return 0;
        }

        int target = (s + diff) / 2;
        
        return solve(arr, target, n);
    }
}



// Approach 3: Bottom Up
// T.C       : O(n*target)
// S.C       : O(n*target)

import java.util.*;

class Solution {
    public int countPartitions(int[] arr, int diff) {
        int n = arr.length;
        
        int[][] t = new int[n + 1][target + 1];
        int s = 0;
        for (int num : arr) {
            s += num;
        }

        if ((s + diff) % 2 != 0) {
            return 0;
        }

        int target = (s + diff) / 2;
        t[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int skip = t[i - 1][j];
                
                int take = 0;
                if (arr[i - 1] <= j) {
                    take = t[i - 1][j - arr[i - 1]];
                }
                
                t[i][j] = take + skip;
            }
        }
        return t[n][target];
    }
}


// Approach 4: Bottom Up Space Optimized
// T.C       : O(n*target)
// S.C       : O(target) 


import java.util.*;

class Solution {
    public int countPartitions(int[] arr, int diff) {
        int n = arr.length;
        
        int[] prev = new int[target + 1];
        int[] curr = new int[target + 1];
        
        int s = 0;
        for (int num : arr) {
            s += num;
        }

        if ((s + diff) % 2 != 0) {
            return 0;
        }

        int target = (s + diff) / 2;

        prev[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int skip = prev[j];
                
                int take = 0;
                if (arr[i - 1] <= j) {
                    take = prev[j - arr[i - 1]];
                }
                
                curr[j] = take + skip;
            }
            // Copy elements from curr to prev
            prev = curr.clone();
        }
        return prev[target];
    }
}
