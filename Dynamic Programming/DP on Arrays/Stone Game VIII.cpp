/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/stone-game-viii/
*/


/**************************************************************** C++ ****************************************************************/

// Approach 1: Recursion
// T.C       : O(2^n)
// S.C       : O(n) 

class Solution {
public:
    int n;

    int solve(int i, vector<int>& prefixSum) {
        if (i == n-1) {
            return prefixSum[n-1];
        }

        int take = prefixSum[i] - solve(i+1, prefixSum);

        int skip = solve(i+1, prefixSum);

        return max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> prefixSum(n, 0);

        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        return solve(1, prefixSum);
    }
};

// Approach : Recursion + Memoization
// T.C      : O(n)
// S.C      : O(n) 

class Solution {
public:
    int n;
    int t[100001];

    int solve(int i, vector<int>& prefixSum) {
        if (i == n-1) {
            return prefixSum[n-1];
        }

        if (t[i] != -1) {
            return t[i];
        }

        int take = prefixSum[i] - solve(i+1, prefixSum);

        int skip = solve(i+1, prefixSum);

        return t[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        memset(t, -1, sizeof(t));
        
        vector<int> prefixSum(n, 0);

        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        return solve(1, prefixSum);
    }
};

// Approach : Bottom up DP
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> t(n);

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        // Base case
        t[n-1] = prefixSum[n-1];

        for (int i = n-2; i >= 1; i--) {
            int take = prefixSum[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }
        return t[1];
    }
};

/**************************************************************** JAVA ****************************************************************/



// Approach 1: Recursion
// T.C       : O(2^n)
// S.C       : O(n) 

import java.util.Arrays;

class Solution1 {
    private int n;

    private int solve(int i, int[] prefixSum) {
        if (i == n - 1) {
            return prefixSum[n - 1];
        }
        
        int take = prefixSum[i] - solve(i + 1, prefixSum);
        int skip = solve(i + 1, prefixSum);
        
        return Math.max(take, skip);
    }

    public int stoneGameVIII(int[] stones) {
        n = stones.length;
        int[] prefixSum = new int[n];
        prefixSum[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        
        return solve(1, prefixSum);
    }
}


// Approach : Recursion + Memoization
// T.C      : O(n)
// S.C      : O(n) 

import java.util.Arrays;

class Solution2 {
    private int n;
    private int[] t;

    private int solve(int i, int[] prefixSum) {
        if (i == n - 1) {
            return prefixSum[n - 1];
        }
        
        if (t[i] != -1) {
            return t[i];
        }
        
        int take = prefixSum[i] - solve(i + 1, prefixSum);
        int skip = solve(i + 1, prefixSum);
        
        return t[i] = Math.max(take, skip);
    }

    public int stoneGameVIII(int[] stones) {
        n = stones.length;
        t = new int[n + 1];
        Arrays.fill(t, -1);
        
        int[] prefixSum = new int[n];
        prefixSum[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        
        return solve(1, prefixSum);
    }
}


// Approach : Bottom up DP
// T.C      : O(n)
// S.C      : O(n)


import java.util.Arrays;

class Solution3 {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        int[] t = new int[n];
        int[] prefixSum = new int[n];
        prefixSum[0] = stones[0];
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        
        // Base case
        t[n - 1] = prefixSum[n - 1];
        
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i + 1];
            
            t[i] = Math.max(take, skip);
        }
        
        return t[1];
    }
}
