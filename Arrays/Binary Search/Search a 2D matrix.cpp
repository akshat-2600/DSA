/*
    Company Tags                : 
    Leetcode Link               :  https://leetcode.com/problems/search-a-2d-matrix/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Binary search on matrix
// T.C      : O(log(m*n))
// S.C      : O(1)  


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int col = mid % n;
            int row = mid / n;
            int ele = matrix[row][col];

            if (ele < target) {
                l = mid + 1;
            } else if (ele > target) {
                r = mid - 1;
            } else if (ele == target) {
                return true;
            }
        }
        return false;
    }   
};


/**************************************************************** JAVA ****************************************************************/

// Approach : Binary search on matrix
// T.C      : O(log(m*n))
// S.C      : O(1)  

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int m = matrix.length;
        int n = matrix[0].length;

        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int row = mid / n;
            int col = mid % n;
            int ele = matrix[row][col];

            if (ele < target) {
                l = mid + 1;
            } else if (ele > target) {
                r = mid - 1; 
            } else if (ele == target) {
                return true;
            }
        }
        return false;
    }
}