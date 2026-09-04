/*
    Company Tag     : GOOGLE , META , EBAY
    Leetcode Link   : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/
*/


/*************************************************************** C++ *************************************************/

//Approach 1 - Pure Recursion
//T.C : O(maxJump^n)
//S.C : O(1)

class Solution {
public:
    int n;
    
    bool solve(int i, vector<int> &nums) {
        if (i >= n-1)     {
            return true;
        }
        
        int maxJump = nums[i];
        for (int jump = maxJump; jump > 0; jump--) {
            if (solve(i+jump, nums)) {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        
        return solve(0, nums);
    }
};

//Approach 2 - Recursion + Memoization
//T.C : O(n*maxJump)
//S.C : O(n)

class Solution {
public:
    int n;
    
    int solve(int i, vector<int> &nums, vector<int> &t) {
        if (i >= n-1) {
            return 1;
        }

        if (t[i] != -1) {
            return t[i];
        }
        
        int maxJump = nums[i];
        for (int jump = maxJump; jump > 0; jump--) {
            if (solve(i+jump, nums, t) == 1) {
                return t[i] = 1;
            }
        }
        return t[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n+1, -1);
        
        bool flag = solve(0, nums, t);
        return flag;
    }
};


//Approach 3 - Bottom UP DP
//T.C : O(n*maxJump)
//S.C : O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> t(n, false);

        t[n-1] = true;
        
        for (int i = n - 2; i >= 0; i--) {
            int maxJump = nums[i];

            for (int jump = 1; jump <= maxJump; jump++) {
                if (i + jump >= n-1 || t[i + jump]) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[0];
    }
};


//Approach 4 - Greedy (Optimal)
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;

        for (int i = 0; i < n; i++) {
            if (i > maxReachable) {
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};

/*************************************************************** JAVA *************************************************/

// coming soon

