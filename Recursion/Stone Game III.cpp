/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/stone-game-iii/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Recursion
// T.C      : O(3^n)
// S.C      : O(n)  recursion stack 


class Solution {
public:
    int n;

    int solve(vector<int>& stones, int i) {
        if (i >= n) {
            return 0;
        }

        int result = stones[i] - solve(stones, i+1);

        if (i + 1 < n) {
            result = max(result, stones[i] + stones[i+1] - solve(stones, i+2));
        }
        
        if (i + 2 < n) {
            result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));
        }
        return result;
    }

    string stoneGameIII(vector<int>& stones) {
        
        n = stones.size();

        int diff = solve(stones, 0);  // Alice - Bob

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        } else {
            return "Tie";
        }
    }
};

// Approach : Memoization 
// T.C      : O(n)
// S.C      : O(n)  recursion stack

class Solution {
public:
    int n;
    vector<int> t;

    int solve(vector<int>& stones, int i) {
        if (i >= n) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int result = stones[i] - solve(stones, i+1);

        if (i + 1 < n) {
            result = max(result, stones[i] + stones[i+1] - solve(stones, i+2));
        }
        
        if (i + 2 < n) {
            result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));
        }
        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stones) {
        
        n = stones.size();

        t.assign(n+1, -1);

        int diff = solve(stones, 0);  // Alice - Bob

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        } else {
            return "Tie";
        }
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach : Recursion 
// T.C      : O(3^n)
// S.C      : O(n)  recursion stack

class Solution {
    int n;

    int solve(int[] stones, int i) {
        if (i >= n) {
            return 0;
        }

        int result = stones[i] - solve(stones, i+1);

        if (i + 1 < n) {
            result = Math.max(result, stones[i] + stones[i+1] - solve(stones, i+2));
        }

        if (i + 2 < n) {
            result = Math.max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));
        }

        return result;
    }

    public String stoneGameIII(int[] stones) {
        n = stones.length;

        int diff = solve(stones, 0);  // Alice - Bob

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        } else {
            return "Tie";
        }
    }
}

// Approach : Memoization 
// T.C      : O(n)
// S.C      : O(n)  recursion stack

class Solution {
    int n;
    int[] t;

    int solve(int[] stones, int i) {
        if (i >= n) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int result = stones[i] - solve(stones, i+1);

        if (i + 1 < n) {
            result = Math.max(result, stones[i] + stones[i+1] - solve(stones, i+2));
        }

        if (i + 2 < n) {
            result = Math.max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));
        }

        return t[i] = result;
    }

    public String stoneGameIII(int[] stones) {
        n = stones.length;

        t = new int[n+1];

        Arrays.fill(t, -1);

        int diff = solve(stones, 0);  // Alice - Bob

        if (diff < 0) {
            return "Bob";
        } else if (diff > 0) {
            return "Alice";
        } else {
            return "Tie";
        }
    }
}