// T.C : O(n)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(7);
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    
    int idx = 0;
    while (true) {
        n -= arr[idx];
        if (n <= 0) {
            cout << idx + 1;
            break;
        }
        idx = (idx + 1) % 7;
    }
    return 0;
}
