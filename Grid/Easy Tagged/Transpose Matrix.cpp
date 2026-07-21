/*
    Company Tags       : 
    LeetCode Link      :  https://leetcode.com/problems/transpose-matrix/


/************************************************************ C++ ************************************************************/

// T.C : O(n^2)
// S.C : O(n^2)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> result(n, vector<int>(m)); // n * m

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};


/************************************************************ Java ************************************************************/

// T.C : O(n^2)
// S.C : O(n^2)

class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] result = new int[n][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
}