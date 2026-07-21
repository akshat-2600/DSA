/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/largest-odd-number-in-string/description/


/************************************************************ C++ ************************************************************/

// Approach : Iterating from right to left and find last odd number and then returning the result
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        for (int i = n-1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);  // T.C : O(1) considering this because this line will run only once (its actual complexity is O(n))
            }
        }
        return "";
    }
};


/************************************************************ Java ************************************************************/

// Approach : Iterating from right to left and find last odd number and then returning the result
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();

        for (int i = n-1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 != 0) {
                return num.substring(0, i+1);   // T.C : O(1) considering this because this line will run only once (its actual complexity is O(n))
            }
        }
        return "";
    }
}