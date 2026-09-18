// T.C : O(N + M)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        
        cin >> n >> m;
        
        vector<string> grid(n);
        
        for (auto& row : grid) {
            cin >> row;
        }
        
        int count = 0;
        
        // Last row must contain only R 
        for (int j = 0; j < m; j++) {
            if (j != m-1 && grid[n-1][j] != 'R') {
                count++;
            }
        }
        
        // Last column must contain only D 
        for (int i = 0; i < n; i++) {
            if (i != n-1 && grid[i][m-1] != 'D') {
                count++;
            }
        }
        cout << count << endl;
    }
}
