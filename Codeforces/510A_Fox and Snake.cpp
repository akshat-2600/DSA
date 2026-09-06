// T.C : O(n*m)
// S.C : O(1)

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<char>> ans(n, vector<char>(m, '#'));
    bool firstUsed = false;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            if (firstUsed == false) {
                for (int j = 0; j < m-1; j++) {
                    ans[i][j] = '.';
                    if (j+1 == m-1) {
                        firstUsed = true;
                    }
                }
            } else {
                for (int j = 1; j < m; j++) {
                    ans[i][j] = '.';
                    if (j == m-1) {
                        firstUsed = false;
                    }
                }
            } 
        }
    }
    
    // output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}