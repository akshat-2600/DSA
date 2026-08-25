/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/smallest-missing-multiple-of-k/description/
*/


/**************************************************************** C++ ****************************************************************/


// T.C       : O(n)
// S.C       : O(n) 

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        
        int ans = k;
        while (seen.find(ans) != seen.end()) {
            ans += k;
        }
        return ans;
    }
};

/**************************************************************** JAVA ****************************************************************/




