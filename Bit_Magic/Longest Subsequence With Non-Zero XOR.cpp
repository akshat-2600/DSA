/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : XOR logic -> if any two bits are same we get 0
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xor_total = 0;
        bool allZero = true;

        for (int num : nums) {
            xor_total ^= num;
            if (num != 0) allZero = false;
        }

        if (allZero == true) {
            return 0;
        }

        return xor_total == 0 ? n-1 : n;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : XOR logic -> if any two bits are same we get 0
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;

        int xor_total = 0;
        boolean allZero = true;

        for (int num : nums) {
            xor_total ^= num;
            if (num != 0) allZero = false;
        }

        if (allZero == true) return 0;

        return xor_total == 0 ? n-1 : n;
    }
}