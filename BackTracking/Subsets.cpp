/*
    Company Tags   :  
    LeetCode Link  :  https://leetcode.com/problems/subsets/description/

/************************************************************ C++ ************************************************************/

// Approach : BackTracking
// T.C      : O(N * 2^N)
// S.C      : O(N)

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i+1, temp);
        temp.pop_back();
        solve(nums, i+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);

        return result;
    }
};

/************************************************************ Java ************************************************************/

// Approach : BackTracking
// T.C      : O(N * 2^N)
// S.C      : O(N)

class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public void solve(int[] nums, int i, List<Integer> temp) {
        if (i == nums.length) {
            result.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[i]);
        solve(nums, i+1, temp);

        temp.remove(temp.size() - 1);

        solve(nums, i+1, temp);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> temp = new ArrayList<>();

        solve(nums, 0, temp);
        return result;
    }
}