/*
    Company Tags           :  
    LeetCode Link          : https://leetcode.com/problems/shift-2d-grid/description/
*/


/************************************************************ C++ ************************************************************/

// T.C : O(m * n * k)
// S.C : O(1)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> temp(grid);

        while (k > 0) {
            for (int i=0; i < m; i++) {
                for (int j=0; j < n; j++) {

                    if (i == m-1 && j == n-1) {
                        temp[0][0] = grid[m-1][n-1];
                    } else if (j == n-1) {
                        temp[i+1][0] = grid[i][n-1];
                    } else {
                        temp[i][j+1] = grid[i][j];
                    }
                }
            }
            k--;
            grid = temp;
        }
        return temp;
    }
};

// T.C : O(m * n)
// S.C : O(1)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
    
        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int oldIndex = i * n + j;

                int newIndex = (oldIndex + k) % total;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};


// Approach : In place conversion

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        int n = row * col;

        k = k % n;
        if (k == 0) return grid;

        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(grid[i/col][i%col], grid[j/col][j%col]);
                i++;
                j--;
            }
        };

        reverse(0, n-1);  // reverse the the whole grid
        reverse(0, k-1);  // reverse the firt k elements
        reverse(k, n-1);  // reverse the rest elements

        return grid;
    }
};

/************************************************************ Java ************************************************************/

// will update

