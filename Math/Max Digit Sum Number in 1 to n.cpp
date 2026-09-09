/*
    Company Tags    :   
    Leetcode Link   :   https://www.geeksforgeeks.org/problems/biggest-integer-having-maximum-digit-sum1704/1

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Brute Force
// T.C        : O(n * log10(n))
// S.C        : O(1)   

class Solution {
  public:
    int findMax(int n) {
        int maxSum = 0;
        int maxNum = 0;
        
        for (int i = 1; i <= n; i++) {
            int x = i;
            int sum = 0;
            while (x != 0) {
                int dig = x % 10;
                sum += dig;
                x /= 10;
            }
            if (sum >= maxSum) {
                maxSum = sum;
                maxNum = i;
            }
        }
        return maxNum;
    }
};

// Approach-2 : Optimized Approach
// T.C        : O((log10(n))^2)
// S.C        : O(1)  

class Solution {
  public:
    int findMax(int n) {
        if (n < 10) {
            return n;
        }

        long long firstNum = n;

        long long sumX = 0;
        
        string stringNum = to_string(n);

        int l = stringNum.length();

        long long x = firstNum;

        while (x != 0) {
            int dig = x % 10;
            sumX += dig;
            
            x /= 10;
        }
        
        long long ans = n;
        long long highestSum = sumX;
        
        for (int i=l-1; i > 0; i--) {
            
            long long extra = stoll(stringNum.substr(i, l-i)) + 1;

            long long secondNum = firstNum - extra;
            
            long long sumY = 0;
            
            long long y = secondNum;
            
            while (y != 0) {
                int dig = y % 10;
                sumY += dig;
                y /= 10;
            }

            if (highestSum < sumY) {
                ans = secondNum;
                
                highestSum = sumY;
            }
        }
        
        return ans;
    }
};

/******************************************************** JAVA ********************************************************/

//coming soon