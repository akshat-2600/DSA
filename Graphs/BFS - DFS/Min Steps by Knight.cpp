/*
    Company Tags        :   Flipkart , Amazon , Microsoft , OYO Rooms , MakeMyTrip , Goldman Sachs , Intuit, Linkedin 
    GeekForGeeks Link   :   https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

*/


/******************************************************** C++ ********************************************************/

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


