/*
    Company Tags        :   Flipkart , Amazon , Microsoft , OYO Rooms , MakeMyTrip , Goldman Sachs , Intuit, Linkedin 
    GeekForGeeks Link   :   https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

*/


/******************************************************** C++ ********************************************************/

// Time Complexity  : O(8^(n^2))
// Space Complexity : O(n^2)

class Solution {
  public:
    // Modified to match 1-based indexing commonly used for this problem
    bool isValid(int i, int j, int n) {
        return i >= 1 && i <= n && j >= 1 && j <= n;   
    }
  
    int solve(int i, int j, int tar_x, int tar_y, int n, vector<vector<bool>>& visited) {
        // Base Case 1: Target reached
        if (i == tar_x && j == tar_y) {
            return 0;
        }
        
        // Base Case 2: Out of bounds or already visited in the current path
        if (!isValid(i, j, n) || visited[i][j]) {
            return INT_MAX;
        }
        
        // Mark the current cell as visited to prevent cycles
        visited[i][j] = true;
        
        int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX, m4 = INT_MAX;
        int m5 = INT_MAX, m6 = INT_MAX, m7 = INT_MAX, m8 = INT_MAX;
        
        // 1. up left
        int res1 = solve(i-2, j-1, tar_x, tar_y, n, visited);
        if (res1 != INT_MAX) m1 = 1 + res1;
        
        // 2. up right
        int res2 = solve(i-2, j+1, tar_x, tar_y, n, visited);
        if (res2 != INT_MAX) m2 = 1 + res2;
        
        // 3. down left
        int res3 = solve(i+2, j-1, tar_x, tar_y, n, visited);
        if (res3 != INT_MAX) m3 = 1 + res3;
        
        // 4. down right
        int res4 = solve(i+2, j+1, tar_x, tar_y, n, visited);
        if (res4 != INT_MAX) m4 = 1 + res4;
        
        // 5. right up
        int res5 = solve(i-1, j+2, tar_x, tar_y, n, visited);
        if (res5 != INT_MAX) m5 = 1 + res5;
        
        // 6. right down
        int res6 = solve(i+1, j+2, tar_x, tar_y, n, visited);
        if (res6 != INT_MAX) m6 = 1 + res6;
        
        // 7. left up
        int res7 = solve(i-1, j-2, tar_x, tar_y, n, visited);
        if (res7 != INT_MAX) m7 = 1 + res7;
        
        // 8. left down
        int res8 = solve(i+1, j-2, tar_x, tar_y, n, visited);
        if (res8 != INT_MAX) m8 = 1 + res8;
        
        // Backtrack: Unmark this cell so it can be used by alternative paths
        visited[i][j] = false;
        
        return min({m1, m2, m3, m4, m5, m6, m7, m8});
    }
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int src_x = knightPos[0];
        int src_y = knightPos[1];
        
        int tar_x = targetPos[0];
        int tar_y = targetPos[1];
        
        // Visited grid to keep track of current path (1-indexed size: n + 1)
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        
        int ans = solve(src_x, src_y, tar_x, tar_y, n, visited);
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};


// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)

class Solution {
  public:
    bool isValid(int x, int y, int n) {
        return (x >= 1 && x <= n && y >= 1 && y <= n);
    }
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int src_x = knightPos[0];
        int src_y = knightPos[1];
        int tar_x = targetPos[0];
        int tar_y = targetPos[1];
        
        if (src_x == tar_x && src_y == tar_y) {
            return 0;
        }
        
        vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
        
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{src_x, src_y}, 0});
        visited[src_x][src_y] = true;
        
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int curr_x = curr.first.first;
            int curr_y = curr.first.second;
            int steps  = curr.second;
            
            if (curr_x == tar_x && curr_y == tar_y) {
                return steps;
            }
            
            for (int i = 0; i < 8; i++) {
                int next_x = curr_x + dx[i];
                int next_y = curr_y + dy[i];
                
                if (isValid(next_x, next_y, n) && !visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    q.push({{next_x, next_y}, steps+1});
                }
            }
        }
        return -1;
    }
};


