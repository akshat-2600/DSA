/*
    Company Tag       : 
    Leetcode Link     : https://leetcode.com/problems/find-pivot-index/description/
*/


/*************************************************************** C++ *************************************************/

// T.C   : O(n^2)
// S.C   : O(1)  

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int leftSum  = 0;
            int rightSum = 0;

            for (int j = 0; j <= i-1; j++) {
                leftSum += nums[j];
            }
            for (int k = i+1; k < n; k++) {
                rightSum += nums[k];
            }
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};


// T.C   : O(n)
// S.C   : O(n)  

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightSum(n, 0);

        for (int i = n-1; i >= 0; i--) {
            rightSum[i] = nums[i] + (i+1 < n ? rightSum[i+1] : 0);
        }
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                leftSum += nums[i-1];
            }
            if ((i+1 < n ? rightSum[i+1] : 0) - leftSum == 0) {
                return i;
            }
        }
        return -1;
    }
};