/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/number-of-good-pairs/description/
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(N^2)
// S.C : O(1)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) count++;
            }
        }
        return count;
    }
};



/**************************************************************** JAVA ****************************************************************/
 

// T.C : O(N^2)
// S.C : O(1)

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (nums[i] == nums[j]) count++;
            }
        }
        return count;
    }
}