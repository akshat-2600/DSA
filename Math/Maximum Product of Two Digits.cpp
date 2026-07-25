/*
    Company Tags         :  
    LeetCode Link        :   https://leetcode.com/problems/maximum-product-of-two-digits/description/


/**************************************************************** C++ ****************************************************************/

// Approach : First calculating largest and second_largest by taking every digit of n and then simply multiplying largest*second_largest
// T.C      : O(log(N))
// S.C      : O(1)

class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int second_largest = 0;

        int temp = n;

        while (temp != 0) {
            int dig = temp % 10;
            if (dig > largest) {
                second_largest = largest;
                largest = dig;
            } else {
                second_largest = max(second_largest, dig);
            }
            temp = temp/10;
        }

        return largest * second_largest;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : First calculating largest and second_largest by taking every digit of n and then simply multiplying largest*second_largest
// T.C      : O(log(N))
// S.C      : O(1)

class Solution {
    public int maxProduct(int n) {
        
        int largest = 0;
        int second_largest = 0;

        int temp = n;

        while (temp != 0) {

            int dig = temp % 10;

            if (dig > largest) {
                second_largest = largest;
                largest        = dig;
            } else {
                second_largest = Math.max(second_largest, dig);
            }
            temp = temp / 10;
        }
        return largest * second_largest;
    }
}