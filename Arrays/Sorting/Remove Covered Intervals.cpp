/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/remove-covered-intervals/description
*/


/**************************************************************** C++ ****************************************************************/

// T.C : O(n * log(n))
// S.C : O(1)


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Sort by start ascending, and if tie, by end descending
        auto lambda = [](vector<int>& i1, vector<int>& i2) {
            if (i1[0] == i2[0]) return i1[1] > i2[1];
            return i1[0] < i2[0];
        };
        
        sort(intervals.begin(), intervals.end(), lambda);
        
        int minNum = intervals[0][0];
        int maxNum = intervals[0][1];
        int count = 0; // Count of covered intervals
        
        for(int i = 1; i < n; i++) {
            // Check if current interval is covered by previous
            if (minNum <= intervals[i][0] && intervals[i][1] <= maxNum) {
                count++;
            } else {
                // Update the range
                minNum = min(minNum, intervals[i][0]);
                maxNum = max(maxNum, intervals[i][1]);
            }
        }
        
        // Return number of non-covered intervals
        return n - count;
    }
};


/**************************************************************** JAVA ****************************************************************/

// T.C : O(n * log(n))
// S.C : O(1)


class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        
        int n = intervals.length;

        // Sort by start ascending, and if tie, by end descending
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });

        int minNum = intervals[0][0];
        int maxNum = intervals[0][1];

        int count = 0;

        for (int i=1; i<n; i++) {
            
            // check if current interval is covered
            if (minNum <= intervals[i][0] && intervals[i][1] <= maxNum) {
                count++;

            } else {
                // Update the range
                minNum = Math.min(minNum, intervals[i][0]);
                maxNum = Math.max(maxNum, intervals[i][1]);
            }
        }

        // return number of non-covered intervals
        return n - count;
    }
}