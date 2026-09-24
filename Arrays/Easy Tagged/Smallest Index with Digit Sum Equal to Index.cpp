/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

*/


/******************************************************** C++ ********************************************************/

// T.C   : O(n)
// S.C   : O(1)


class Solution {
public:
    bool check(int n, int idx) {
        int temp = n;
        int sum  = 0;

        while (temp != 0) {
            int dig = temp % 10;
            sum += dig;
            temp /= 10;
        }
        if (sum == idx) {
            return true;
        }
        return false;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (check(nums[i], i)) {
                return i;
            }
        }
        return -1;
    }
};

