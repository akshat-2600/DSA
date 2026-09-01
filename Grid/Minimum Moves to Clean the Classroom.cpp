/*  
    Company Tags                  : 
    Leetcode Link                 : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/



/****************************************************************** C++ ****************************************************/


//T.C : O(n * m * maxEnergy * 2^10)
//S.C : O(n * m * maxEnergy * 2^10)

class Solution {
public:
    using VB    = vector<bool>;
    using VVB   = vector<VB>;
    using VVVB  = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startR = 0;
        int startC = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1; // 2^litterCount-1

        if (litterCount == 0) {
            return 0;
        }

        VVVVB visited(m, VVVB(n, VVB(maxEnergy+1, VB((1 << litterCount), false))));

        queue<State> q;
        q.push({startR, startC, maxEnergy, 0});
        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;
        while (!q.empty()) {
            int currSize = q.size();

            while (currSize--) {
                State curr = q.front();
                q.pop();

                if (curr.collectedMask == allCollected) {
                    return moves;
                }

                if (curr.energyLeft == 0) {
                    continue;
                }

                for (auto &dir : directions) {
                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) {
                        continue;
                    }

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') continue;

                    int nextEnergy = curr.energyLeft - 1;
                    int nextCollectedMask = curr.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    } else if (cell == 'L') {
                        nextCollectedMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if (!visited[nextRow][nextCol][nextEnergy][nextCollectedMask]) {
                        visited[nextRow][nextCol][nextEnergy][nextCollectedMask] = true;
                        q.push({nextRow, nextCol, nextEnergy, nextCollectedMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};