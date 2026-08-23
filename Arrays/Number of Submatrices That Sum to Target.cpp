/*
    Company Tags    :   FAMOUS
    LeetCode Link   :   https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
*/


/**************************************************************** C++ ****************************************************************/

// Approach : Brute Force
// T.C      : O(m^3 * n^3)
// S.C      : O(1)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int sr = 0; sr < m; sr++) {
            for (int sc = 0; sc < n; sc++) {
                    
                for (int er = sr; er < m; er++) {
                    for (int ec = sc; ec < n; ec++) {

                        int sum = 0;
                        for (int i = sr; i <= er; i++) {
                            for (int j = sc; j <= ec; j++) {
                                sum += matrix[i][j];
                            }
                        }
                        if (sum == target) result++;
                    }
                }
            }
        }
        return result;
    }
};

// Approach : Cummulative Sum + Hashing
// T.C      : O(n^2 * m)
// S.C      : O(m)


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // row wise cumSum
        for (int row = 0; row < m; row++) {
            for (int col = 1; col < n; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
        // find the number of subarrays with sum == target in downwards movement
        for (int startCol = 0; startCol < n; startCol++) {
            for (int j = startCol; j < n; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cumSum = 0;

                for (int row = 0; row < m; row++) {
                    cumSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol-1] : 0);

                    if (mp.find(cumSum - target) != mp.end()) {
                        result += mp[cumSum - target];
                    }
                    mp[cumSum]++;
                }
            }
        }
        return result;
    }
};


/**************************************************************** JAVA ****************************************************************/

// comming soon
