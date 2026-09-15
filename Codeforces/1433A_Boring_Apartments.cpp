// T.C : O(1)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        
        int n;
        cin >> n;
        string s = to_string(n);
        
        int len = s.length();
        
        if (s[0] == '1') {
            cout << (len*(len+1)) / 2 << endl;
            continue;
        } else {
            int dig = (s[0] - '0') - 1;
            int ans = 10 * dig + (len*(len+1)) / 2;
            cout << ans << endl;
            continue;
        }
    }
}

