/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
*/


/************************************************************ C++ ************************************************************/

// T.C : O(n + log(min(a, b)))
// S.C : O(1)


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

    int findGCD(vector<int>& nums) {
        
        int max_element = INT_MIN;
        int min_element = INT_MAX;

        for (int ele : nums) {
            max_element = max(max_element, ele);
            min_element = min(min_element, ele);
        }

        return gcd(max_element, min_element);
    }
};


/************************************************************ JAVA ************************************************************/

// T.C : O(n + log(min(a, b)))
// S.C : O(1)

class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int findGCD(int[] nums) {
        
        int max_element = Integer.MIN_VALUE;
        int min_element = Integer.MAX_VALUE;

        for (int ele : nums) {
            max_element = Math.max(max_element, ele);
            min_element = Math.min(min_element, ele);
        }

        return gcd(max_element, min_element);
    }
}