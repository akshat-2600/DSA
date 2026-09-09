/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/count-commas-in-range-ii/description/
*/


/******************************************************** C++ ********************************************************/

// # Intuition

// The number of commas used while writing a number depends only on its number of digits.

// For example:

// * Numbers from `1` to `999` contain `0` commas.
// * Numbers from `1,000` to `999,999` contain `1` comma each.
// * Numbers from `1,000,000` to `999,999,999` contain `2` commas each.

// Instead of checking every number individually, we can process numbers in groups having the same number of digits. For each group, we calculate how many numbers are present and multiply it by the number of commas required for each number.

// # Approach

// 1. If `n < 1000`, no number requires a comma, so return `0`.

// 2. Start from `1000`, since this is the first number containing a comma.

// 3. Process numbers in ranges based on their digit count.

// 4. For every range:

//    * Calculate the number of digits of the current starting number.
//    * Determine how many commas each number in that digit range contains.
//    * Calculate how many numbers belong to that range.
//    * Add the total commas contributed by that range.

// 5. Continue increasing the range size until the next complete range exceeds `n`.

// 6. Finally, calculate the remaining numbers from the current position up to `n` and add their comma contribution.

// This avoids iterating through every number from `1` to `n`, making the solution efficient even for large values of `n`.

// # Complexity

// * Time complexity: \(O(\log n)\)

//   We process the number ranges based on digit groups, and the number of such groups is proportional to the number of digits in `n`.

// * Space complexity: \(O(1)\)

//   Only a constant amount of extra space is used.


// CODE

class Solution {
public:
    long long countCommas(long long n) {
        
        if (n < 1000) {
            return 0;
        }
        
        long long i = 1000;
        long long count = 0;
        long long inc = 900;
        while (i + (inc*10) <= n) {
            int countDig = log10(i) + 1;
            inc *= 10;
            if (countDig % 3 == 0) {
                count += ((countDig/3) - 1) * inc;
            } else {
                count += (countDig/3) * inc;
            }
            i += inc;
        }
        long long rem = n - i + 1;
        int countDig = log10(i) + 1;
        if (countDig % 3 == 0) {
            count += ((countDig/3) - 1) * rem;
        } else {
            count += (countDig/3) * rem;
        }
        return count;
    }
};

/******************************************************** JAVA ********************************************************/

//coming soon