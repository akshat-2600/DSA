/*
    Company Tags                : Google, Microsoft, Goldman Sach
    Leetcode Link               : https://leetcode.com/problems/shortest-common-supersequence/
*/

/************************************************************** C++ **************************************************************/
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> t(m+1, vector<int>(n+1));

        for (int i=0; i < m+1; i++) {
            for (int j=0; j < n+1; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = i+j;
                } else if (str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
                }
            }
        }

        string result = "";

        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                result.push_back(str1[i-1]);
                i--;
                j--;
            } else {
                if (t[i-1][j] < t[i][j-1]) {
                    result.push_back(str1[i-1]);
                    i--;
                } else {
                    result.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while (i > 0) {
            result.push_back(str1[i-1]);
            i--;
        }

        while (j > 0) {
            result.push_back(str2[j-1]);
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/************************************************************** JAVA ***************************************************************/

class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int[][] t = new int[m+1][n+1];

        for (int i=0; i < m+1; i++) {
            for (int j=0; j < n+1; j++) {

                if (i == 0 || j == 0) {
                    t[i][j] = i+j;
                } else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = 1 + Math.min(t[i-1][j], t[i][j-1]);
                }
            }
        }

        StringBuilder result = new StringBuilder();
        int i = m;
        int j = n;

        while (i > 0 && j > 0) {
            if (str1.charAt(i-1) == str2.charAt(j-1)) {
                result.append(str1.charAt(i-1));
                i--;
                j--;
            } else {
                if (t[i-1][j] < t[i][j-1]) {
                    result.append(str1.charAt(i-1));
                    i--;
                } else {
                    result.append(str2.charAt(j-1));
                    j--;
                }
            }
        }

        while (i > 0) {
            result.append(str1.charAt(i-1));
            i--;
        }

        while (j > 0) {
            result.append(str2.charAt(j-1));
            j--;
        }

        return result.reverse().toString();
    }
}