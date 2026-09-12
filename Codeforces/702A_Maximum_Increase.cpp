// T.C : O(N)
// S.C : O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << 0;
        return 0;
    }
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (int i = 1; i < n; i++) {
        if (vec[i] > vec[i - 1]) {
            currentLen++;
        } else {
            currentLen = 1;
        }
        maxLen = max(maxLen, currentLen);
    }
    
    cout << maxLen;
    return 0;
}
