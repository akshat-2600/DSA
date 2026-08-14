/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/search-insert-position/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Binary search
// T.C      : O(log(n))
// S.C      : O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

/**************************************************************** JAVA ****************************************************************/


// Approach : Binary search
// T.C      : O(log(n))
// S.C      : O(1)


class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}

