/*
    Company Tags                        : 
    Leetcode Link                       : https://leetcode.com/problems/min-cost-climbing-stairs/description/
    
*/

// Approach : Recursion 
// T.C      : O(2^n)
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    int solve(int i, vector<int>& cost, int n) {
        if (i >= n) {
            return 0;
        }

        int step1 = cost[i] + solve(i+1, cost, n);
        int step2 = cost[i] + solve(i+2, cost, n);

        return min(step1, step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int ansIdx0 = solve(0, cost, n);
        int ansIdx1 = solve(1, cost, n);

        return min(ansIdx0, ansIdx1);
    }
};

// Approach : Memoization 
// T.C      : O(n^2)
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    int solve(int i, vector<int>& cost, int n, vector<int>& t) {
        if (i >= n) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int step1 = cost[i] + solve(i+1, cost, n, t);
        int step2 = cost[i] + solve(i+2, cost, n, t);

        return t[i] = min(step1, step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();

        vector<int> t(n+1, -1);

        int ansIdx0 = solve(0, cost, n, t);
        int ansIdx1 = solve(1, cost, n, t);

        return min(ansIdx0, ansIdx1);
    }
};

// Approach : Bottom up dp
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n + 1, 0);
        
        // Base case: t[n] is 0 (already set by vector init)
        
        for (int i = n - 1; i >= 0; i--) {
            int step1 = cost[i] + t[i + 1];
            int step2 = (i + 2 <= n) ? cost[i] + t[i + 2] : cost[i];
            t[i] = min(step1, step2);
        }
        
        return min(t[0], t[1]);
    }
};
