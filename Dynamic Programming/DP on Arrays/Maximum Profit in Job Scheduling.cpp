/*
    Company Tags        : 
    Leetcode Link       :  https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
*/


/********************************************************************* C++ ****************************************************************/

// Approach : Recurrsion + Memoization
// T.C      : O(N * log(n))
// S.C      : O(N)

class Solution {
public:
    int n;
    vector<int> dp;

    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int next = getNextIndex(array, i+1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);

        return dp[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>> array(n, vector<int>(3, 0)); // {start, end, profit}
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        };

        sort(array.begin(), array.end(), comp);

        dp.resize(n+1, -1);

        return solve(array, 0);
    }
};



/********************************************************************* JAVA ****************************************************************/

// Approach : Recurrsion + Memoization
// T.C      : O(N * log(n))
// S.C      : O(N)

class Solution {
    int n;
    private int[] dp;

    private int getNextIndex(int[][] array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    private int solve(int[][] array, int i) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int next = getNextIndex(array, i+1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);

        return dp[i] = Math.max(taken, notTaken);
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = startTime.length;

        int[][] array = new int[n][3];

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        Arrays.sort(array, Comparator.comparingInt(vec->vec[0]));

        dp = new int[n];
        Arrays.fill(dp, -1);

        return solve(array, 0);
    }
}