/*
    Company Tag                 : 
    Leetcode Link               : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/
*/


/*************************************************************** C++ *************************************************/

//Approach - Greedy
//T.C : O(n)
//S.C : O(1)


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 1;
        }

        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        int maxIdx = INT_MIN;
        int minIdx = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (maxNum < nums[i]) {
                maxNum = nums[i];
                maxIdx = i;
            }
            if (minNum > nums[i]) {
                minNum = nums[i];
                minIdx = i;
            }
        }

        int maxNumFromStart = maxIdx + 1;
        int minNumFromStart = minIdx + 1;

        int maxNumFromEnd   = n - maxIdx;
        int minNumFromEnd   = n - minIdx;

        int case1 = min(maxNumFromStart, minNumFromStart) + min(maxNumFromEnd, minNumFromEnd);
        int case2 = max(maxNumFromStart, minNumFromStart);
        int case3 = max(maxNumFromEnd, minNumFromEnd);

        return min({case1, case2, case3});

    }
};



/*************************************************************** JAVA *************************************************/

//Approach - Greedy
//T.C : O(n)
//S.C : O(1)

class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        if (n == 1) {
            return 1;
        }

        int maxNum = Integer.MIN_VALUE;
        int minNum = Integer.MAX_VALUE;
        int maxIdx = -1;
        int minIdx = -1;

        for (int i = 0; i < n; i++) {
            if (maxNum < nums[i]) {
                maxNum = nums[i];
                maxIdx = i;
            }

            if (minNum > nums[i]) {
                minNum = nums[i];
                minIdx = i;
            }
        }

        int maxNumFromStart = maxIdx + 1;
        int minNumFromStart = minIdx + 1;

        int maxNumFromEnd   = n - maxIdx;
        int minNumFromEnd   = n - minIdx;

        int case1 = Math.min(maxNumFromStart, minNumFromStart) + Math.min(maxNumFromEnd, minNumFromEnd);
        int case2 = Math.max(maxNumFromStart, minNumFromStart);
        int case3 = Math.max(maxNumFromEnd, minNumFromEnd);

        return Math.min(case1, Math.min(case2, case3));
    }
}