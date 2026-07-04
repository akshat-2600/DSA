/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/
*/

/************************************************************ C++ ************************************************************************/

//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        //result[i][j] = min health to reach from [0][0] to [i][j]

        deque<pair<int, int>> deq;

        result[0][0] = grid[0][0];
        deq.push_front({0, 0});

        while (!deq.empty()) {
            auto [r, c] = deq.front();
            deq.pop_front();

            for (auto& dir: directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (grid[nr][nc] + result[r][c] < result[nr][nc]) {
                    result[nr][nc] = grid[nr][nc] + result[r][c];

                    if (grid[nr][nc] == 0) {
                        deq.push_front({nr, nc});
                    } else {
                        deq.push_back({nr, nc});
                    }
                }
            }
        }
        int x = result[m-1][n-1];
        return health - x >= 1;    
    }
};

/************************************************************ JAVA ************************************************************************/

//T.C : O(m*n)
//S.C : O(m*n)


class Solution {
    int[][] directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();

        int[][] result = new int[m][n];
        for (int i=0; i<m; i++) {
            Arrays.fill(result[i], Integer.MAX_VALUE);
        }

        Deque<int[]> deq = new ArrayDeque<>();

        result[0][0] = grid.get(0).get(0);
        deq.addFirst(new int[]{0, 0});

        while (!deq.isEmpty()) {
            int[] curr = deq.pollFirst();
            int r = curr[0];
            int c = curr[1];

            if (r == m-1 && c == n-1) break;

            for (int[] dir: directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                int nextGridValue = grid.get(nr).get(nc);

                if (nextGridValue + result[r][c] < result[nr][nc]) {
                    result[nr][nc] = nextGridValue + result[r][c];

                    if (nextGridValue == 0) {
                        deq.addFirst(new int[]{nr, nc});
                    } else {
                        deq.addLast(new int[]{nr, nc});
                    }
                }
            }
        }
        int x = result[m-1][n-1];
        return health - x >= 1;
    }
}

