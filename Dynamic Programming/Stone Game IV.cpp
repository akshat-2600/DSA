/*
    Company Tag      : 
    LeetCode Link    :  https://leetcode.com/problems/stone-game-iv/description/
    
*/

// Approach : Recursion 
// T.C      : O(n * sqrt(n))
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    bool solve(int n) {
        if (n == 0) {
            return false;  // whoever next turn is will loose the game
        }

        for (int k = 1; k*k <= n; k++) {
            if (solve(n - k*k) == false) {  // asking bob whether he won the game or not
                // as bob is returning that he did not won the game there fore alice won the game
                return true;
            }
        }
        return false;  // bob won the game
    }

    bool winnerSquareGame(int n) {
        
        return solve(n); // function to check whether alice wins or not
    }
};


// Approach : Memoization 
// T.C      : O(n * sqrt(n))
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    bool solve(int n, int t[]) {
        if (n == 0) {
            return false;  // whoever next turn is will loose the game
        }

        if (t[n] != -1) {
            return t[n];
        }

        for (int k = 1; k*k <= n; k++) {
            if (solve(n - k*k, t) == false) {  // asking bob whether he won the game or not
                // as bob is returning that he did not won the game there fore alice won the game
                return t[n] = true;
            }
        }
        return t[n] = false;  // bob won the game
    }

    bool winnerSquareGame(int n) {
        int t[n+1];
        memset(t, -1, sizeof(t));

        return solve(n, t); // function to check whether alice wins or not
    }
};


// Approach : Bottom up dp
// T.C      : O(n * sqrt(n))
// S.C      : O(n)


class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> t(n+1, false);

        for (int i = 0; i < n+1; i++) {
            for (int k = 1; k*k <= i; k++) {
                if (t[i - k*k] == false) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n] == true;
    }
};