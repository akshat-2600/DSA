/*
    Company Tags        : 
    Leetcode Link       :  https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/

/********************************************************************* C++ ****************************************************************/

// T.C      : O(log(n) with base 10)
// S.C      : O(1)

class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum  = 0;
        int temp = n;

        while (temp != 0) {
            int dig = temp % 10;
            sum  += dig;
            prod *= dig;
            temp /= 10;
        }
        cout << prod << " " << sum << endl;
        int res = sum + prod;

        return (n % res == 0 ? true : false);
    }
};


/********************************************************************* JAVA ****************************************************************/

// T.C      : O(log(n) with base 10)
// S.C      : O(1)


class Solution {
    public boolean checkDivisibility(int n) {
        int prod = 1;
        int sum  = 0;
        int temp = n;

        while (temp != 0) {
            int dig = temp % 10;
            sum += dig;
            prod *= dig;
            temp /= 10;
        }
        int res = sum + prod;

        return (n % res == 0 ? true : false);
    }
}