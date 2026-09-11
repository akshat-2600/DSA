/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/k-modulus-array-element0255/1

*/


/******************************************************** C++ ********************************************************/

// T.C : O(N + sqrt(max(arr))
// S.C : O(1)

#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return -1;

        // Step 1: Check if all elements are equal
        bool all_equal = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                all_equal = false;
                break;
            }
        }
        if (all_equal) return -1;

        // Step 2: Compute GCD of differences between consecutive/all elements
        int current_gcd = 0;
        for (int i = 1; i < n; i++) {
            int diff = abs(arr[i] - arr[0]);
            current_gcd = std::gcd(current_gcd, diff);
        }

        // Step 3: Count total positive divisors of the calculated GCD
        int divisor_count = 0;
        for (int i = 1; i * i <= current_gcd; i++) {
            if (current_gcd % i == 0) {
                divisor_count++; // i is a divisor
                if (i * i != current_gcd) {
                    divisor_count++; // current_gcd / i is also a distinct divisor
                }
            }
        }

        return divisor_count;
    }
};
