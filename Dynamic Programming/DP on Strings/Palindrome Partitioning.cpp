/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning/
*/


/************************************************************ C++ ************************************************************/

// T.C : O(2^N + N^2)
// S.C : O(N^2)

class Solution {
public:
    void solve(string &s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if (i == s.length()) {
            result.push_back(currPartition);
            return;
        }

        for (int j=i; j < s.length(); j++) {
            if (t[i][j] == true) {
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Initialize the DP table for palindromic substrings
        // t[i][j] = true -> s[i...j] is a palindrome

        for (int i=0; i < n; i++) {
            t[i][i] = true; // substring of single character is always a palindrome
        }

        for (int L=2; L <= n; L++) {
            for (int i=0; i < n-L+1; i++) {

                int j = i+L-1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i+1][j-1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result);

        return result;
    }
};

/************************************************************ JAVA ************************************************************/

// T.C : O(2^N + N^2)
// S.C : O(N^2)

class Solution {

    private void solve(String s, int i, List<String> currPartition, boolean[][] dp, List<List<String>> result) {

        if (i == s.length()) {
            result.add(new ArrayList<>(currPartition));
            return;
        }

        for (int j=i; j < s.length(); j++) {
            if (dp[i][j]) {
                currPartition.add(s.substring(i, j+1));
                solve(s, j+1, currPartition, dp, result);
                currPartition.remove(currPartition.size()-1);
            }
        }
    }

    public List<List<String>> partition(String s) {

        int n = s.length();
        boolean[][] dp = new boolean[n][n];

        // Every single character is a palindrome
        for (int i=0; i < n; i++) {
            dp[i][i] = true;
        } 

        // Fill dp table
        for (int L = 2; L <= n; L++) {
            for (int i=0; i+L-1 < n; i++) {

                int j = i + L - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    if (L == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }

        List<List<String>> result = new ArrayList<>();
        solve(s, 0, new ArrayList<>(), dp, result);

        return result;
    }
}