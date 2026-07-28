/*
    Company Tags       : 
    Leetcode Link      :  https://leetcode.com/problems/permutations/description
*/


/**************************************************************** C++ ****************************************************************/

// Appraoch : Backtracking
// T.C      : O(n * n!)
// S.C      : O(n)  (recursion stack)

class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx) {
        if (idx == n) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);

            solve(nums, idx+1);

            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        solve(nums, 0);

        return result;
    }
};

/**************************************************************** JAVA ****************************************************************/

// Appraoch : Backtracking
// T.C      : O(n * n!)
// S.C      : O(n)  (recursion stack)

class Solution {
    private List<List<Integer>> result;
    private int n;

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i]  = nums[j];
        nums[j]  = temp;
    }

    private void solve(int[] nums, int idx) {
        if (n == idx) {
            List<Integer> currentPermute = new ArrayList<>();
            for (int num : nums) {
                currentPermute.add(num);
            }
            result.add(currentPermute);
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(nums, idx, i);
            solve(nums, idx+1);
            swap(nums, idx, i);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        result = new ArrayList<>();
        n = nums.length;

        solve(nums, 0);
        return result;
    }
}