/*
    Company Tags   :  AMAZON , META
    LeetCode Link  :  https://leetcode.com/problems/increasing-triplet-subsequence/description/

/************************************************************ C++ ************************************************************/

// Approach : Longest Increasing subsequence (recursion)
// T.C      : O(2^n)
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    bool solve(vector<int>& nums, int i, int n, vector<int>& temp) {
        if (temp.size() == 3) {
            return true;
        }

        if (i >= n) return false;

        bool take = false;

        if (temp.empty() || temp.back() < nums[i]) {
            temp.push_back(nums[i]);
            take = solve(nums, i+1, n, temp);
            temp.pop_back();
        } 
        bool skip = solve(nums, i+1, n, temp);
        
        return take || skip;
    }   


    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        return solve(nums, 0, n, temp);
    }
};


// Approach : Best Approach using three variables num1, num2, num3
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        int num3 = INT_MAX;

        for (int num : nums) {
            num3 = num;

            if (num3 <= num1) {
                num1 = num3;
            } else if (num3 <= num2) {
                num2 = num3;
            } else {
                return true;
            }
        }

        return false;
    }
};

/************************************************************ Java ************************************************************/

// Approach : Longest Increasing subsequence (recursion)
// T.C      : O(2^n)
// S.C      : O(n)  (recursion stack)

class Solution {
    boolean solve(int[] nums, int i, int n, ArrayList<Integer> temp) {
        if (temp.size() == 3) {
            return true;
        }

        if (i >= n) return false;

        boolean take = false;

        if (temp.isEmpty() || temp.get(temp.size() - 1) < nums[i]) {
            temp.add(nums[i]);
            take = solve(nums, i+1, n, temp);
            temp.remove(temp.size() - 1);
        }

        boolean skip = solve(nums, i+1, n, temp);

        return take || skip;
    }

    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;

        ArrayList<Integer> temp = new ArrayList<>();

        return solve(nums, 0, n, temp);
    }
}


// Approach : Best Approach using three variables num1, num2, num3
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public boolean increasingTriplet(int[] nums) {
        int num1 = Integer.MAX_VALUE;
        int num2 = Integer.MAX_VALUE;
        int num3 = Integer.MAX_VALUE;

        for (int num : nums) {
            num3 = num;
            if (num3 <= num1) {
                num1 = num3;
            } else if (num3 <= num2) {
                num2 = num3;
            } else {
                return true;
            }
        }
        return false;
    }
}