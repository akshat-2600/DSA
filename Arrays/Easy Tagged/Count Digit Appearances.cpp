/*
    Company Tags         :  
    LeetCode Link        :  https://leetcode.com/problems/count-digit-appearances/


/**************************************************************** C++ ****************************************************************/

// T.C : O(N * (log(digit)))
// S.C : O(1)

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;

        for (int num : nums) {
            int temp = num;

            while (temp != 0) {
                int dig = temp % 10;
                if (dig == digit) count++;

                temp /= 10;
            }    
        }
        return count;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(N * (log(digit)))
// S.C : O(1)

class Solution {
    public int countDigitOccurrences(int[] nums, int digit) {

        int count = 0;

        for (int num : nums) {
            int temp = num;

            while (temp != 0) {
                int dig = temp % 10;
                if (dig == digit) count++;

                temp /= 10;
            }
        }
        return count;
    }
}