/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/smallest-divisible-digit-product-i/

/************************************************************ C++ ************************************************************************/

//T.C : O(k log (n))
//S.C : O(1)

class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while (true) {
            int temp = n;
            int prod = 1;
            while (temp != 0) {
                int dig = temp%10;
                temp /= 10;
                prod *= dig;
            }
            if (prod % t == 0) {
                return n;
            } else{
                n += 1;
                prod = 1;
            }
        }
        return -1;
    }
};

/************************************************************ JAVA ************************************************************************/

