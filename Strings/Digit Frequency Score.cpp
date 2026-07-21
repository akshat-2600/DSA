/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/digit-frequency-score/description/

/************************************************************ C++ ************************************************************/

// Approach : Using map to store frequency and then calculating frequency
// T.C      : O(no. of digits)
// S.C      : O(1)

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;

        while (n != 0) {
            int dig = n % 10;
            mp[dig]++;

            n /= 10;
        }

        int freq = 0;

        for (auto [p1, p2] : mp) {
            freq += (p1 * p2);
        }
        return freq;
    }
};


/************************************************************ Java ************************************************************/

// Approach : Using map to store frequency and then calculating frequency
// T.C      : O(no. of digits)
// S.C      : O(1)

class Solution {
    public int digitFrequencyScore(int n) {
        
        n = Math.abs(n);

        if (n == 0) return 0;

        int[] counts = new int[10];

        while (n != 0) {
            int dig = n % 10;
            counts[dig]++;
            n /= 10;
        }

        int freq = 0;

        for (int i = 0; i < 10; i++) {
            if (counts[i] > 0) {
                freq += (i * counts[i]);
            }
        }
        return freq;
    }
}