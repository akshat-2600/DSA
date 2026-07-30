/*
    Company Tags   : 
    LeetCode Link  :  https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/

/************************************************************ C++ ************************************************************/


// Approach 1 : Greedy / Counting - > Greedy strategy to distribute distinct characters across 8 keys minimizing push count.
// T.C        : O(n)
// S.C        : O(1)

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        if (n <= 8) {
            return n;
        }

        int count = 0;
        int idx = 1;

        while (n > 8) {
            count += idx * 8;
            idx++;
            n -= 8;
        }
        count += (n * idx);

        return count;
    }
};


// Approach 2 : Calculating pushes by iterating over string
// T.C        : O(n)
// S.C        : O(1)

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        int pushes = 0;

        for (int i = 0; i < n; i++) {
            pushes += (i/8) + 1;
        }

        return pushes;
    }
};


/************************************************************ Java ************************************************************/

// Approach 1 : Greedy / Counting - > Greedy strategy to distribute distinct characters across 8 keys minimizing push count.
// T.C        : O(n)
// S.C        : O(1)


class Solution {
    public int minimumPushes(String word) {
        int n = word.length();

        if (n <= 8) {
            return n;
        }

        int count = 0;
        int idx = 1;

        while (n > 8) {
            count += (idx * 8);
            idx++;
            n -= 8;
        }

        count += (idx * n);

        return count;
    }
}


// Approach 2 : Calculating pushes by iterating over string
// T.C        : O(n)
// S.C        : O(1)

class Solution {
    public int minimumPushes(String word) {
        int n = word.length();

        int pushes = 0;

        for (int i = 0; i < n; i++) {
            pushes += (i/8) + 1;
        }

        return pushes;
    }
}