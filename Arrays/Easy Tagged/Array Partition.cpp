/*
    Company Tags         :  
    LeetCode Link        :  https://leetcode.com/problems/array-partition/description/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n*log(n) + n)
// S.C : O(1)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C : O(n*log(n) + n)
// S.C : O(1)

class Solution {
    public int arrayPairSum(int[] nums) {
        
        Arrays.sort(nums);

        int sum = 0;
        for (int i = 0; i < nums.length; i += 2) {
            sum += nums[i];
        }

        return sum;
    }
}