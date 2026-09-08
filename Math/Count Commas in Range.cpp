/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/count-commas-in-range/description/

*/


/******************************************************** C++ ********************************************************/

// Approach 1 : Brute Force
// T.C        : O(n)
// S.C        : O(1)

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        int count = 0;

        for (int i = 1000; i <= n; i++) {
            int countDig = log10(i) + 1;
            cout << i << ":" << countDig << endl;

            if (countDig % 3 == 0) {
                count += ((countDig / 3) == 1) ? (countDig / 3) : (countDig / 3) - 1;
            } else {
                count += (countDig / 3);
            }
        }
        return count;
    }
};


// Approach 2 : multiple if conditions valid for 1e5
// T.C        : O(1)
// S.C        : O(1)

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        int count = 0;
        
        if (n == 100000) {
            count += n - 1000 + 1;
        }

        if (n <= 99999 && n >= 10000) {
            count += (n - 1000 + 1); 
        }

        if (n <= 9999 && n >= 1000) {
            count += (n - 1000 + 1);
        }
        
        return count;
    }
};


// Approach 3 : Optimized for range 1e5
// T.C        : O(1)
// S.C        : O(1)


class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 1000 + 1;
    }
};
