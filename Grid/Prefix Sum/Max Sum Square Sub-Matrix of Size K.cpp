/*
    Company Tags         :   ADOBE
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/coins-of-geekland--141631/1
*/


/**************************************************************** C++ ****************************************************************/

// Approach :  finds the maximum \(k \times k\) subgrid sum by precomputing row-wise prefix sums to calculate each subgrid's row totals in O(1) time.
// T.C      : O(N^2 + K * (N-K)^2)
// S.C      : O(N^2)

class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        
        vector<vector<int>> grid(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            grid[i][0] = mat[i][0];
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                
                grid[i][j] = mat[i][j] + grid[i][j-1];
            }
        }
        
        int maxSum = INT_MIN;
        
        for (int r = 0; r <= n - k; r++) { 
            for (int c = 0; c <= n - k; c++) { 
                int sum = 0; 
                
                
                for (int z = r; z < r + k; z++) { 
                    int right_idx = c + k - 1;
                    sum += (c == 0) ? grid[z][right_idx] : (grid[z][right_idx] - grid[z][c - 1]); 
                } 
                
                maxSum = max(maxSum, sum); 
            } 
        } 
        
        return maxSum;
    }
};


/**************************************************************** JAVA ****************************************************************/

// Approach :  finds the maximum \(k \times k\) subgrid sum by precomputing row-wise prefix sums to calculate each subgrid's row totals in O(1) time.
// T.C      : O(N^2 + K * (N-K)^2)
// S.C      : O(N^2)

class Solution {
    public int maximumSum(int[][] mat, int k) {
        
        int n = mat.length;
        
        int[][] grid = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            grid[i][0] = mat[i][0];
        }
        
        // Calculate prefix sum for each row
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                
                grid[i][j] = mat[i][j] + grid[i][j-1];
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        
        for (int r = 0; r <= n - k; r++) {
            for (int c = 0; c <= n - k; c++) {
                int sum = 0;
                
                for (int z = r; z < r + k; z++) {
                    int rightIdx = c + k - 1;
                    sum += (c == 0) ? grid[z][rightIdx] : (grid[z][rightIdx] - grid[z][c - 1]);
                }
                
                maxSum = Math.max(maxSum, sum);
            }
        }
        return maxSum;
        
    }
}