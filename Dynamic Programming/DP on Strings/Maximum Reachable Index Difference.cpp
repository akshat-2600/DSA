/*
    Company Tags           : 
    GeekForGeeks Link      : https://www.geeksforgeeks.org/problems/maximum-reachable-index-difference/1


/************************************************************ C++ ************************************************************/

// Approach : Pure Recursion
// T.C      : Exponential
// S.C      : O(26)

class Solution {
  public:
    int solve(string& s, int idx, char ch) {
        
        char next = ch + 1;
        int farthest = idx;
        
        // Try every possible jump to the next character
        for (int i = idx+1; i < s.size(); i++) {
            if (s[i] == next) {
                farthest = max(farthest, solve(s, i, next));
            }
        }
        return farthest;
    }
  
    int maxIndexDifference(string &s) {
        
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                int endIndex = solve(s, i, 'a');
                ans = max(ans, endIndex - i);
            }
        }
        
        return ans;
        
    }
};


// Approach : Memoization
// T.C      : O(n^2)
// S.C      : O(n)

class Solution {
  public:
    vector<int> dp;
  
    int solve(string& s, int idx, char ch) {
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        char next = ch + 1;
        int farthest = idx;
        
        // Try every possible jump to the next character
        for (int i = idx+1; i < s.length(); i++) {
            if (s[i] == next) {
                farthest = max(farthest, solve(s, i, next));
            }
        }
        return dp[idx] = farthest;
    }
  
    int maxIndexDifference(string &s) {
        
        int n = s.length();
        int ans = -1;
        
        dp.assign(n, -1);
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                int endIndex = solve(s, i, 'a');
                ans = max(ans, endIndex - i);
            }
        }
        return ans;
        
    }
};


// Approach : Bottom Up DP
// T.C      : O(n^2)
// S.C      : O(n)

class Solution {
  public:
    int maxIndexDifference(string &s) {
        
        int n = s.size();
        
        vector<int> dp(n);
        
        int ans = -1;
        
        for (int i = n-1; i >= 0; i--) {
            
            dp[i] = i;  // if no jump is possible
            
            char next = s[i] + 1;
            
            // Try every possible jump to the next character
            for (int j = i+1; j < n; j++) {
                if (s[j] == next) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            if (s[i] == 'a') {
                ans = max(ans, dp[i] - i);
            }
        }
        
        return ans;
    }
};


// Approach : Optimized DP (Traversing form right to left and storing furthest index reachable from i)
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    int maxIndexDifference(string &s) {

        int n = s.size();

        vector<int> dp(n);

        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {

            int cur = s[i] - 'a';

            dp[i] = i;

            if (cur != 25 && best[cur + 1] != -1)
                dp[i] = best[cur + 1];

            best[cur] = max(best[cur], dp[i]);

            if (cur == 0)
                ans = max(ans, dp[i] - i);
        }

        return ans;
    }
};


/************************************************************ Java ************************************************************/

// Approach : Pure Recursion
// T.C      : Exponential
// S.C      : O(26)

class Solution {
    
    int solve(String s, int idx, char ch) {
        
        char next = (char)(ch + 1);
        int farthest = idx;
        
        // Try every possible jump to the next character
        for (int i = idx + 1; i < s.length(); i++) {
            if (s.charAt(i) == next) {
                farthest = Math.max(farthest, solve(s, i, next));
            }
        }
        
        return farthest;
    }
    
    public int maxIndexDifference(String s) {
        
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                int endIndex = solve(s, i, 'a');
                ans = Math.max(ans, endIndex - i);
            }
        }
        return ans;
    }
}


// Approach : Memoization
// T.C      : O(n^2)
// S.C      : O(n)

class Solution {
    int[] dp;
    
    private int solve(String s, int idx, char ch) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        char next = (char)(ch + 1);
        int farthest = idx;
        
        // Try every possible jump to the next character
        for (int i = idx + 1; i < s.length(); i++) {
            if (s.charAt(i) == next) {
                farthest = Math.max(farthest, solve(s, i, next));
            }
        }
        
        return dp[idx] = farthest;
    }
    
    public int maxIndexDifference(String s) {
        
        int n = s.length();
        dp = new int[n];
        
        Arrays.fill(dp, -1);
        
        int ans = -1;
        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a') {
                int endIndex = solve(s, i, 'a');
                ans = Math.max(ans, endIndex - i);
            }
        }
        
        return ans;
    }
}


// Approach : Bottom Up DP
// T.C      : O(n^2)
// S.C      : O(n)

class Solution {
  public:
    int maxIndexDifference(string &s) {
        
        int n = s.size();
        
        vector<int> dp(n);
        
        int ans = -1;
        
        for (int i = n-1; i >= 0; i--) {
            
            dp[i] = i;  // if no jump is possible
            
            char next = s[i] + 1;
            
            // Try every possible jump to the next character
            for (int j = i+1; j < n; j++) {
                if (s[j] == next) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            if (s[i] == 'a') {
                ans = max(ans, dp[i] - i);
            }
        }
        
        return ans;
    }
};


// Approach : Optimized DP (Traversing form right to left and storing furthest index reachable from i)
// T.C      : O(n)
// S.C      : O(n)

class Solution {
    public int maxIndexDifference(String s) {
        
        int n = s.length();
        
        int[] dp = new int[n];
        
        int[] best = new int[26];
        Arrays.fill(best, -1);
        
        int ans = -1;
        
        for (int i = n-1; i >= 0; i--) {
            
            int cur = s.charAt(i) - 'a';
            dp[i] = i;
            
            if (cur != 25 && best[cur + 1] != -1) {
                dp[i] = best[cur + 1];
            }
            
            best[cur] = Math.max(best[cur], dp[i]);
            
            if (cur == 0) {
                ans = Math.max(ans, dp[i] - i);
            }
        }
        return ans;
    }
}