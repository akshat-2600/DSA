/*
    Company Tags       : 
    Leetcode Link      :  https://leetcode.com/problems/maximum-subarray/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Brute Force
// T.C      : O(n^2)
// S.C      : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int curr = 0;
            for (int j = i; j < nums.size(); j++) {
                curr += nums[j];

                if (curr > maxSum) {
                    maxSum = curr;
                }
            }
        }

        return maxSum;
    }
};


// Approach : Kadane's Algorithm
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int val : nums) {
            currSum += val;
            maxSum = max(currSum , maxSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach : Brute Force
// T.C      : O(n^2)
// S.C      : O(1)

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        
        for (int i = 0; i < nums.length; i++) {
            int curr = 0;
            for (int j = i; j < nums.length; j++) {
                curr += nums[j];

                if (curr > maxSum) {
                    maxSum = curr;
                }
            }
        }

        return maxSum;
    }
}


// Approach : Kadane's Algorithm
// T.C      : O(n)
// S.C      : O(1)


class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum  = Integer.MIN_VALUE;
        int currSum = 0;

        for (int num : nums) {
            currSum += num;

            maxSum = Math.max(currSum, maxSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
}
