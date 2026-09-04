/*  
    Company Tags    : 
    LeetCode Link   :  https://leetcode.com/problems/smallest-stable-index-i/description/
*/

/****************************************************************** C++ ****************************************************/

// T.C      : O(N)
// S.C      : O(N)



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxNum(n);
        vector<int> minNum(n);
        maxNum[0]   = nums[0];
        minNum[n-1] = nums[n-1];

        for (int i = 1; i < n; i++) {
            maxNum[i] = max(maxNum[i-1], nums[i]);
        }

        for (int j = n-2; j >= 0; j--) {
            minNum[j] = min(minNum[j+1], nums[j]);
        }

        for (int i = 0; i < n; i++) {
            int score = maxNum[i] - minNum[i];
            if (score <= k) {
                return i;
            }
        }
        return -1;
    }
};
