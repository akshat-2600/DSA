/*
    Company Tags                :  
    Leetcode Link               :  https://www.geeksforgeeks.org/problems/geeks-island--170646/1
*/


/**************************************************************** C++ ****************************************************************/

// O(V + E) => O((N*M) + 4(N*M)) => O(5(N*M)) => O(N*M)


// T.C : O(N * M)
// S.C : O(N * M)

class Solution {
  public:
    int n, m;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
        
        visited[i][j] = true;
        
        for (int k=0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && mat[ni][nj] >= mat[i][j]) {
                
                dfs(ni, nj, mat, visited);
            }
        }
    }
  
    int countCoordinates(vector<vector<int>>& mat) {
        
        n = mat.size();
        m = mat[0].size();
        
        vector<vector<bool>> P(n, vector<bool>(m, false));
        vector<vector<bool>> Q(n, vector<bool>(m, false));
        
        // Station P (Top boundary)
        for (int j=0; j < m; j++) {
            if (!P[0][j]) {
                dfs(0, j, mat, P);
            }
        }
        
        // Station P (Left boundary)
        for (int i=0; i < n; i++) {
            if (!P[i][0]) {
                dfs(i, 0, mat, P);
            }
        }
        
        // Station Q (Bottom boundary)
        for (int j=0; j < m; j++) {
            if (!Q[n-1][j]) {
                dfs(n-1, j, mat, Q);
            }
        }
        
        // Station Q (Right boundary)
        for (int i=0; i < n; i++) {
            if (!Q[i][m-1]) {
                dfs(i, m-1, mat, Q);
            }
        }
        
        int ans = 0;
        
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (P[i][j] && Q[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};



/**************************************************************** JAVA ****************************************************************/

// T.C : O(N * M)
// S.C : O(N * M)

class Solution {
    private int n, m;
    
    private final int[] dx = {-1, 1, 0, 0};
    private final int[] dy = {0, 0, -1, 1};
    
    private void dfs(int i, int j, int[][] mat, boolean[][] visited) {
        visited[i][j] = true;
        
        for (int k=0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && mat[ni][nj] >= mat[i][j]) {
                dfs(ni, nj, mat, visited);
            }
        }
    }
    
    public int countCoordinates(int[][] mat) {
        
        n = mat.length;
        m = mat[0].length;
        
        boolean[][] P = new boolean[n][m];
        boolean[][] Q = new boolean[n][m];
        
        // Station P (Top boundary)
        for (int j=0; j < m; j++) {
            if (!P[0][j]) {
                dfs(0, j, mat, P);
            }
        }
        
        // Station P (Left boundary)
        for (int i=0; i < n; i++) {
            if (!P[i][0]) {
                dfs(i, 0, mat, P);
            }
        } 
        
        // Station Q (Bottom boundary)
        for (int j=0; j < m; j++) {
            if (!Q[n-1][j]) {
                dfs(n-1, j, mat, Q);
            }
        }
        
        // Station Q (Right boundary)
        for (int i=0; i < n; i++) {
            if (!Q[i][m-1]) {
                dfs(i, m-1, mat, Q);
            }
        }
        
        int ans = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (P[i][j] && Q[i][j]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
}