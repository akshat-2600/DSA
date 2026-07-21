/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/single-number/


/************************************************************ C++ ************************************************************/

// Approach : Sorting the array and then comparing adjacent elements
// T.C      : O(n * log(n))
// S.C      : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};

// Approach : Using xor on all elements leaves single at end
// T.C      : O(n)
// S.C      : O(1)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};



/************************************************************ Java ************************************************************/

// Approach : Sorting the array and then comparing adjacent elements
// T.C      : O(n * log(n))
// S.C      : O(1)

class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 1; i += 2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[nums.length - 1];
    }
}


// Approach : Using xor on all elements leaves single at end
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public int singleNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
}