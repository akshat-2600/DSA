/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/



/**************************************************************** C++ ****************************************************************/

// Approach : Calculating even and odd sum using for loop and then calculating GCD
// T.C      : O(log(min(a, b)) + n)
// S.C      : O(1)

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {

        int sumOdd  = 0;
        int sumEven = 0;

        for (int i=1; i <= 2*n; i++) {
            if (i % 2 == 0) {
                sumEven += i;
            } else {
                sumOdd += i;
            }
        }

        return gcd(sumEven, sumOdd);
    }
};

// Approach : Calculating even and odd sum using formula and then calculating GCD
// T.C      : O(log(min(a, b)))
// S.C      : O(1)

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {

        int sumEven  =  n * (n + 1);
        int sumOdd =  n * n;

        return gcd(sumEven, sumOdd);
    }
};


/*********************************************************** JAVA **************************************************/

// Approach : Calculating even and odd sum using for loop and then calculating GCD
// T.C      : O(log(min(a, b)) + n)
// S.C      : O(1)

class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int gcdOfOddEvenSums(int n) {
        
        int sumEven = 0;
        int sumOdd  = 0;

        for (int i=1; i <= 2*n; i++) {
            if (i % 2 == 0) {
                sumEven += i;
            } else {
                sumOdd += i;
            }
        }

        return gcd(sumEven, sumOdd);
    }
}

// Approach : Calculating even and odd sum using formula and then calculating GCD
// T.C      : O(log(min(a, b)))
// S.C      : O(1)

class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int gcdOfOddEvenSums(int n) {
        
        int sumEven = n * (n + 1);
        int sumOdd  = n * n;

        return gcd(sumEven, sumOdd);
    }
}


