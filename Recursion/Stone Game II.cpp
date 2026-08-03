/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/stone-game-ii/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Recursion + Game Strategy
// T.C      : O(4^n)
// S.C      : O(n)

class Solution {
public:
    int n;

    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2*M, n - i); x++) {
            stones += piles[i+x-1];

            if (person == 1) {  // alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { // Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
        }
        return result;
    }
    

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        return solveForAlice(piles, 1, 0, 1);
    }
};


// Approach : Memoization + Game Strategy
// T.C      : O(n^3)
// S.C      : O(n^2)

class Solution {
public:
    int n;
    int t[2][101][101];

    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }

        if (t[person][i][M] != -1) {
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2*M, n - i); x++) {
            stones += piles[i+x-1];

            if (person == 1) {  // alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { // Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
        }
        return t[person][i][M] = result;
    }
    

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(t, -1, sizeof(t));

        return solveForAlice(piles, 1, 0, 1);
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : Recursion + Game Strategy
// T.C      : O(4^n)
// S.C      : O(n)

class Solution {
    int n;

    int solveForAlice(int[] piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }

        int result = (person == 1) ? -1 : Integer.MAX_VALUE;

        int stones = 0;

        for (int x = 1; x <= Math.min(2*M, n - i); x++) {
            stones += piles[x + i - 1];

            if (person == 1) {// Alice
                result = Math.max(result, stones + solveForAlice(piles, 0, i + x, Math.max(x, M)));
            } else { // Bob
                result = Math.min(result, solveForAlice(piles, 1, i + x, Math.max(x, M)));
            }
        }
        return result;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;

        return solveForAlice(piles, 1, 0, 1);
    }
}

// Approach : Memoization + Game Strategy
// T.C      : O(n^3)
// S.C      : O(n^2)

class Solution {
    int n;
    int[][][] t;

    int solveForAlice(int[] piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }

        if (t[person][i][M] != -1) {
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : Integer.MAX_VALUE;

        int stones = 0;

        for (int x = 1; x <= Math.min(2*M, n - i); x++) {
            stones += piles[x + i - 1];

            if (person == 1) {// Alice
                result = Math.max(result, stones + solveForAlice(piles, 0, i + x, Math.max(x, M)));
            } else { // Bob
                result = Math.min(result, solveForAlice(piles, 1, i + x, Math.max(x, M)));
            }
        }
        return t[person][i][M] = result;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;

        t = new int[2][n+1][n+1];
        for (int i = 0; i < 2; i++) {
            for (int[] row : t[i]) {
                Arrays.fill(row, -1);
            }
        }

        return solveForAlice(piles, 1, 0, 1);
    }
}