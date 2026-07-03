/*
    Company Tags                : 
    GeekForGeeks Link           : https://www.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one2236/1?_gl=1*1ed2q77*_up*MQ..&gclid=Cj0KCQiA49XMBhDRARIsAOOKJHZRNAAZienXIkpogHQ2I3rSfKT8IT3jVQg1bi2cDPURBt5pGJnkMM8aAgqDEALw_wcB&gbraid=0AAAAAC9yBkBLKTbB4j8YDewdZI2chGPOg 

/************************************************************ C++ ************************************************************************/

// T.C : O(n^2 * m * 26)
// S.C : O(n * m)

class Solution {
  public:
    int dp[101][101];
  
    int solve(string &s1, string &s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1+solve(s1, s2, i+1, j+1);
        }
        return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
        
    }
  
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        memset(dp, -1, sizeof(dp));
        
        int oldLCS = solve(s1, s2, 0, 0);
        
        int ways = 0;
        
        for (int pos=0; pos <= s1.length(); pos++) {
            for (char ch='a'; ch <= 'z'; ch++) {
                string temp = s1;
                temp.insert(temp.begin()+pos, ch);
                
                memset(dp, -1, sizeof(dp));
                
                int cur = solve(temp, s2, 0, 0);
                
                if (cur == oldLCS+1) {
                    ways++;
                }
            }
        }
        
        return ways;
        
    }
};



// T.C : O(n * m)
// S.C : O(n * m)


class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        // pref[i][j] = LCS of s1[0...i-1] ans s2[0...j-1]
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        
        for (int i=1; i < n+1; i++) {
            for (int j=1; j < m+1; j++) {
                
                if (s1[i-1] == s2[j-1]) {
                    pref[i][j] = 1 + pref[i-1][j-1];
                } else {
                    pref[i][j] = max(pref[i-1][j], pref[i][j-1]);
                }
            }
        }
        
        // suff[i][j] = LCS of s1[i...n-1] ans s2[j...m-1]
        vector<vector<int>> suff(n+1, vector<int>(m+1, 0));
        
        for (int i=n-1; i >= 0; i--) {
            for (int j=m-1; j >= 0; j--) {
                
                if (s1[i] == s2[j]) {
                    suff[i][j] = 1 + suff[i+1][j+1];
                } else {
                    suff[i][j] = max(suff[i+1][j], suff[i][j+1]);
                }
            }
        }
        
        int oldLCS = pref[n][m];
        int ways = 0;
        
        // Try every insertion position
        for (int pos=0; pos <= n; pos++) {
            
            // To avoid counting the same inserted string multiple times
            bool used[26] = {false};
            
            // Match inserted character with every position in s2
            for (int j=0; j<m; j++) {
                char ch = s2[j];
                
                if (used[ch - 'a']) continue;
                
                if (pref[pos][j] + 1 + suff[pos][j+1] == oldLCS+1) {
                    ways++;
                    used[ch - 'a'] = true;
                }
            }
        }
        return ways;
    }
};





/************************************************************ JAVA ************************************************************************/

// T.C : O(n^2 * m * 26)
// S.C : O(n * m)


class Solution {
    int[][] dp = new int[101][101];
    
    int solve(String s1, String s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }
        return dp[i][j] = Math.max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }
    
    public int waysToIncreaseLCSBy1(String s1, String s2) {
        
        for (int i=0; i < 101; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        int oldLCS = solve(s1, s2, 0, 0);
        
        int ways = 0;
        
        for (int pos = 0; pos <= s1.length(); pos++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                
                StringBuilder temp = new StringBuilder(s1);
                temp.insert(pos, ch);
                
                for (int i=0; i<101; i++) {
                    Arrays.fill(dp[i], -1);
                }
                
                int cur = solve(temp.toString(), s2, 0, 0);
                
                if (cur == oldLCS+1) ways++;
            }
        }
        return ways;
    }
}


// T.C : O(n * m)
// S.C : O(n * m)

class Solution {
    public int waysToIncreaseLCSBy1(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        
        // pref[i][j] = LCS of s1[0..n-1] and s2[0....m-1]
        int[][] pref = new int[n+1][m+1];
        
        for (int i=1; i < n+1; i++) {
            for (int j=1; j < m+1; j++) {
                
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    pref[i][j] = 1 + pref[i-1][j-1];
                } else {
                    pref[i][j] = Math.max(pref[i-1][j], pref[i][j-1]);
                }
            }
        }
        
        // suff[i][j] = LCS of s1[i...n-1] and s2[j...m-1]
        int[][] suff = new int[101][101];
        
        for (int i=n-1; i >= 0; i--) {
            for (int j=m-1; j >= 0; j--) {
                
                if (s1.charAt(i) == s2.charAt(j)) {
                    suff[i][j] = 1 + suff[i+1][j+1];
                } else {
                    suff[i][j] = Math.max(suff[i+1][j], suff[i][j+1]);
                }
            }
        }
        
        int oldLCS = pref[n][m];
        int ways = 0;
        
        // Try every insertion position
        for (int pos=0; pos <= n; pos++) {
            
            // To avoid counting the same inserted string multiple times
            boolean[] used = new boolean[26];
            
            // Match inserted character with every position in s2
            
            for (int j=0; j<m; j++) {
                char ch = s2.charAt(j);
                
                if (used[ch - 'a']) {
                    continue;
                }
                
                if (pref[pos][j] + 1 + suff[pos][j+1] == oldLCS + 1) {
                    ways++;
                    used[ch - 'a'] = true;
                }
            }
        }
        
        return ways;
    }
}