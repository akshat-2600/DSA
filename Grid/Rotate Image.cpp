/*
    Company Tags    :   
    LeetCode Link   :  https://leetcode.com/problems/rotate-image/
*/

/**************************************************************** C++ ****************************************************************/
 
// Approach : Taking transpose by swapping elements where i != j & then reversing each row
// T.C      : O(n^2)
// S.C      : O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i != j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};



/**************************************************************** JAVA ****************************************************************/

 
// Approach : Taking transpose by swapping elements where i != j & then reversing each row
// T.C      : O(n^2)
// S.C      : O(1)

class Solution {
    public void rotate(int[][] matrix) {
        
        int n = matrix.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i != j) {
                    int temp      = matrix[i][j];
                    matrix[i][j]  = matrix[j][i];
                    matrix[j][i]  = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = n - 1;

            while (l < r) {
                int temp = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = temp;
                l++;
                r--; 
            }
        }
    }
}