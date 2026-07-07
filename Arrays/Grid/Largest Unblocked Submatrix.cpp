/*
    Company Tags                : 
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/largest-unblocked-submatrix/1?_gl=1*1sbtpvl*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg


/**************************************************************** C++ ****************************************************************/

class Solution {
public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {

        vector<int> rows;
        vector<int> cols;

        for (auto &it : arr) {
            rows.push_back(it[0]);
            cols.push_back(it[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0;
        int prev = 0;

        for (int row : rows) {
            maxRows = max(maxRows, row - prev - 1);
            prev = row;
        }

        maxRows = max(maxRows, n - prev);

        int maxCols = 0;
        prev = 0;

        for (int col : cols) {
            maxCols = max(maxCols, col - prev - 1);
            prev = col;
        }

        maxCols = max(maxCols, m - prev);

        return maxRows * maxCols;
    }
};


/**************************************************************** JAVA ****************************************************************/

class Solution {
    public int largestArea(int n, int m, int[][] arr) {
        
        ArrayList<Integer> rows = new ArrayList<>();
        ArrayList<Integer> cols = new ArrayList<>();
        
        for (int[] it : arr) {
            rows.add(it[0]);
            cols.add(it[1]);
        }
        
        Collections.sort(rows);
        Collections.sort(cols);
        
        int maxRows = 0;
        int prev = 0;
        
        for (int row : rows) {
            maxRows = Math.max(maxRows, row - prev -1);
            prev = row;
        }
        
        maxRows = Math.max(maxRows, n - prev);
        
        int maxCols = 0;
        prev = 0;
        
        for (int col : cols) {
            maxCols = Math.max(maxCols, col - prev - 1);
            prev = col;
        }
        
        maxCols = Math.max(maxCols, m - prev);
        
        return maxRows * maxCols;
        
    }
}