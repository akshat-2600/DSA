/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
*/


/**************************************************************** C++ ****************************************************************/

class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);

            while (i < j && mp.get(nums[j]) > k) {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                i++;
            }

            result = Math.max(result, j - i + 1);
            j++;
        }
        return result;
    }
}

/**************************************************************** JAVA ****************************************************************/

class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);

            while (i < j && mp.get(nums[j]) > k) {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                i++;
            }

            result = Math.max(result, j - i + 1);
            j++;
        }
        return result;
    }
}