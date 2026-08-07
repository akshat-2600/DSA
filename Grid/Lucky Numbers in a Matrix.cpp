/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

/************************************************************ C++ ************************************************************************/

//T.C : O(n ^ 2)
//S.C : O(m + n)

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        for (int i=0; i < m; i++) {
            int min_ele = INT_MAX;
            for (int j = 0; j < n; j++) {
                min_ele = min(min_ele, matrix[i][j]);
            }
            rows[i] = min_ele;
        }

        for (int j = 0; j < n; j++) {
            int max_ele = INT_MIN;
            for (int i = 0; i < m; i++) {
                max_ele = max(max_ele, matrix[i][j]);
            }
            cols[j] = max_ele;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] == cols[j]) {
                    ans.push_back(rows[i]);
                }
            }
        }
        return ans;
    }
};

/************************************************************ JAVA ************************************************************************/

